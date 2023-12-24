#pragma once
// sa3LL.h
// �������������� ����������

#include "syntall.h"

class syntaxan {
public:
    // �����������
    syntaxan(lexan* lex, FILE* parse_stream, FILE* result_stream) {
        this->lex = lex;
        this->parse_stream = parse_stream;
        this->result_stream = result_stream;
    }
    // LL(1)
    int parse(void) {
        lex->parse();
        next_token();
        // �������� � ����� �������
        int i = 0, n = 0;
        ttype at = TOK_EOT, bt = TOK_EOT;
        // ������ �� �����
        ttype s = TOK_EOT;
        // ��������, ��������� �� ����������� �������
        int t = 0;
        // �������������� ������������� TOK_EOT � ���� (��� �����)
        sta.push(TOK_EOT);
        //  ������������� �������� ���������� � ����
        sta.push(START);
        fprintf(parse_stream, "\n");
        // ����������� ���� �������� LL
        while (1) {
            s = clear_stack(); // ������ �� ������� �����
            t = SYNTA[s][tok.type];
            //fprintf(parse_stream, "\nSYNTA[%d][%d] = %d", s, tok.type, t);
            if (t <= 0) {
                //������
                throw(new texception("syntaxan: failure synta", 0, tok.pos));
                return 0;
            }
            else if (t == ACC) {
                // ������
                break;
            }
            else if (t == POP) {
                // ������
                at = sta.pop();
                clear_stack();
                next_token();
            }
            else if (t <= MAX_RULE) {
                // ��� �������
                at = sta.pop();
                n = RLEN[t];
                // ������������ ������� � ���� � �������� �������
                for (i = n - 1; i > -1; i--) {
                    sta.push(bt = RULE[t][i]);
                }
                fprintf(parse_stream, "\npush rule: %d", t);
            }
            else {
                // ������ ����������� �������
                throw (new texception("syntaxan: failure synta", 0, tok.pos));
            }
        }
        printf("\nSYNTAXAN SUCCESS\n");
        fprintf(parse_stream, "\n\nSYNTAXAN SUCCESS\n");
        // ���������� ����� ����� �����
        out(OUT_END);
        strip.fprint(parse_stream);
        strip.print();
        execute();
        return 1;
    }
private:
    // ������ �� ����������� ����������
    lexan* lex;
    // ����� ������ (������)
    FILE* parse_stream;
    // ����� ������ (����������)
    FILE* result_stream;
    // ������� �����
    ttoken tok;
    // ���� ��-��������
    mpstack sta;
    // ������� ��������
    stsyms syms;
    // ����������� ����
    exstack exe;
    // ����� �����
    ststrip strip;
    // ���� �����
    labelstack stl;
    // ���������� ��������� �����  
    void next_token() {
        tok = lex->next_token();
        if (tok.type == TOK_LF) {
            next_token();
        }
        else if (tok.type == TOK_COMMENT) {
            next_token();
        }
    }
    // ������ �� ����� �����
    void out(ttype tt) {
        int i = 0, j = 0;
        ttoken t = tok;
        t.type = tt;
        switch (tt) {
        case OUT_PUSH:
            j = strip.new_label();
            stl.push(j);
            t.word_val = j;
            t.type = OUT_LABEL;
            break;
        case OUT_POPL:
            j = stl.pop();
            t.word_val = j;
            t.type = OUT_LABEL;
            break;
        }
        strip.add(t);
    }
    // ������ ������������ ������� �� ����� 
    ttype clear_stack() {
        ttype s;
        while ((s = sta.top()) > SYM_LAST + 1) {
            s = sta.pop();
            out(s);
        }
        return s;
    }
    // ����������� ������ �����
    void execute() {
        // ��������� ����� �����
        int strip_pointer = 1;
        // ������� �������� �����
        int it_counter = 1;
        // ������� ������� �����
        ttype tp;
        // ���������� ��� ����������
        ttoken x, y;
        int j = 0, val;
        bool m1, m2;
        // ������� ���� ���������� ����� �����
        while (1) {
            // ������� ����������
            x.reset();
            y.reset();
            // ��������� ��� �������� �����
            tp = strip[strip_pointer].type;
            switch (tp) {
            case OUT_END:
                printf("\n\nEXE DONE\n");
                fprintf(result_stream, "\n\nEXE_DONE\n");
                return;
            case OUT_PROGRAM:
                syms.insert(strip[strip_pointer]);
                strip_pointer++;
            case OUT_ID: case OUT_WORD: case OUT_CH: case OUT_QWORD: case OUT_QCH:
                // ������������ � ����
                exe.push(strip[strip_pointer]);
                strip_pointer++;
                break;
            case OUT_DIM:
                exe.pop(y);
                // ��� ����� ����������
                do {
                    exe.pop(x);
                    j = syms.insert(x);

                    if (j == ST_EXISTS) throw (new texception("exe: duplicate declaration", 0, x.pos));
                    syms[j].type = y.type;

                } while (exe.size() != 0);
                strip_pointer++;
                break;
            case OUT_ASS:
                exe_pop(y);
                exe.pop(x);
                j = syms.find(x);
                if (j == ST_NOTFOUND) throw (new texception("exe: identifier not found", 0, x.pos));
                // ���� ������������� char
                if (y.type == OUT_CH) val = char_asc(y.char_val);
                // ���� ������������� word | bool
                else val = y.word_val;
                // ���� ���������� char
                if (syms[j].type == OUT_QCH) {
                    // �������� �������� � ��������� �������� ( ��� word )
                    if (val > 256) val = -1;
                    else if (val > 127 && val < 256) val = val - 128 * 2;
                    else if (val < -128) val = -128;
                    syms[j].char_val = val;
                }
                // ���� ���������� word
                else {
                    if (val < 0 || val > WORD_SIZE) throw (new texception("exe: 'word' can be only between 0 and WORD_SIZE,", WORD_SIZE, x.pos));
                    syms[j].word_val = val;
                }
                // ���������� ��� ���������� ����������������
                syms[j].tok_val.set_str("INIT");
                strip_pointer++;
                break;
                // ��� �������� ���������� (����� QNE)
            case OUT_ADD: case OUT_SUB: case OUT_MUL: case OUT_DIV: case OUT_EQ:
            case OUT_NE: case OUT_LT: case OUT_GT: case OUT_LE: case OUT_GE:
            case OUT_QNE: case OUT_QAND: case OUT_QOR:
                exe_pop(y);
                if (tp != OUT_QNE) exe_pop(x);
                if (x.type == OUT_CH) x.word_val = char_asc(x.char_val);
                if (y.type == OUT_CH) y.word_val = char_asc(y.char_val);
                // ��������� ��������
                switch (tp) {
                case OUT_ADD:
                    if (x.type == OUT_CH || y.type == OUT_CH) throw (new texception("exe: type is not suitable for the operation", 0, x.pos));
                    x.word_val += y.word_val;
                    break;
                case OUT_SUB:
                    if (x.type == OUT_CH || y.type == OUT_CH) throw (new texception("exe: type is not suitable for the operation", 0, x.pos));
                    x.word_val -= y.word_val;
                    break;
                case OUT_MUL:
                    if (x.type == OUT_CH || y.type == OUT_CH) throw (new texception("exe: type is not suitable for the operation", 0, x.pos));
                    x.word_val *= y.word_val;
                    break;
                case OUT_DIV:
                    if (x.type == OUT_CH || y.type == OUT_CH) throw (new texception("exe: type is not suitable for the operation", 0, x.pos));
                    if (y.word_val == 0) throw (new texception("exe: division by zero", 0, x.pos));
                    x.word_val /= y.word_val;
                    break;
                case OUT_EQ:
                    if (x.word_val == y.word_val) {
                        x.word_val = 1; // true
                        x.type = OUT_BOOL;
                    }
                    else {
                        x.word_val = 0; // false
                        x.type = OUT_BOOL; // ��������������� ���������� ���
                    }
                    break;
                case OUT_NE:
                    if (x.word_val != y.word_val) {
                        x.word_val = 1;
                        x.type = OUT_BOOL;
                    }
                    else {
                        x.word_val = 0;
                        x.type = OUT_BOOL;
                    }
                    break;
                case OUT_LT:
                    if (x.word_val < y.word_val) {
                        x.word_val = 1;
                        x.type = OUT_BOOL;
                    }
                    else {
                        x.word_val = 0;
                        x.type = OUT_BOOL;
                    }
                    break;
                case OUT_GT:
                    if (x.word_val > y.word_val) {
                        x.word_val = 1;
                        x.type = OUT_BOOL;
                    }
                    else {
                        x.word_val = 0;
                        x.type = OUT_BOOL;
                    }
                    break;
                case OUT_LE:
                    if (x.word_val <= y.word_val) {
                        x.word_val = 1;
                        x.type = OUT_BOOL;
                    }
                    else {
                        x.word_val = 0;
                        x.type = OUT_BOOL;
                    }
                    break;
                case OUT_GE:
                    if (x.word_val >= y.word_val) {
                        x.word_val = 1;
                        x.type = OUT_BOOL;
                    }
                    else {
                        x.word_val = 0;
                        x.type = OUT_BOOL;
                    }
                    break;
                case OUT_QNE:
                    x = y;
                    if (x.type != OUT_BOOL) {
                        throw
                            (new texception("exe: invalid type for operation 'not'",
                                0, y.pos));
                    }
                    if (x.word_val == 1) x.word_val = 0;
                    else x.word_val = 1;
                    break;
                case OUT_QAND: case OUT_QOR:
                    if (x.type != OUT_BOOL || y.type != OUT_BOOL) {
                        throw (new texception("exe: invalid type for operations 'and', 'or'",
                            0, y.pos));
                    }
                    if (tp == OUT_QAND) {
                        if (x.word_val && y.word_val) x.word_val = 1;
                        else x.word_val = 0;
                    }
                    else {
                        if (x.word_val || y.word_val) x.word_val = 1;
                        else x.word_val = 0;
                    }
                    break;
                }
                exe.push(x);
                strip_pointer++;
                break;
            case OUT_LABEL:
                // ���� ��������� �����, �� ������������ ��
                x.word_val = strip[strip_pointer].word_val;
                x.type = OUT_WORD;
                x.pos = strip[strip_pointer].pos;
                exe.push(x);
                strip_pointer++;
                break;
            case OUT_DEFL:
                // ����������� �����, ��� ����� ��� �� �����
                exe.pop(x);
                strip_pointer++;
                break;
                // ������� �� ���
            case OUT_BZ:
                exe_pop(y);
                exe_pop(x);
                if (x.type != OUT_BOOL) {
                    throw
                        (new texception("exe: invalid type of conditional expression",
                            0, x.pos));
                }
                if (x.word_val == 0) {
                    j = strip.find_DEF(y.word_val);
                    if (j == -1) {
                        throw
                            (new texception("exe: lable not found", 0, x.pos));
                    }
                    strip_pointer = j;
                }
                else {
                    strip_pointer++;
                }
                break;
            case OUT_WRITE:
                exe_pop(y);
                if (y.type == OUT_CH) { printf("\n%c", y.char_val); fprintf(result_stream, "\n%c", y.char_val); }
                else if (y.type == OUT_BOOL && y.word_val == 1) { printf("\ntrue"); fprintf(result_stream, "\ntrue"); }
                else if (y.type == OUT_BOOL && y.word_val == 0) { printf("\nfalse"); fprintf(result_stream, "\nfalse"); }
                else if (y.type == OUT_WORD) { printf("\n%d", y.word_val); fprintf(result_stream, "\n%d", y.word_val); }
                else throw (new texception("exe: invalid type for operation 'write'", 0, strip[strip_pointer].pos));
                strip_pointer++;
                break;
            }
            if (++it_counter > MAX_IT) {
                throw (new texception("exe: deadlock", 0, strip[strip_pointer].pos));
            }
        }
    }
    // ��������� �� ����� ��������
    void exe_pop(ttoken& e) {
        exe.pop(e);
        // ���������� ���� ����������
        if (e.type == OUT_WORD) {}
        else if (e.type == OUT_CH) {}
        else if (e.type == OUT_BOOL) {}
        else if (e.type == OUT_ID) {
            int j = syms.find(e);
            if (j == ST_NOTFOUND) {
                // ������ �� ������
                throw (new texception("exe_pop: identifier not found", 0, e.pos));
            }
            // ���� ���������� �� ����������������
            if (strcmp(syms[j].tok_val.str, "NON_INIT") == 0) {
                throw (new texception("exe_pop: uninitialized variable is used", 0, e.pos));
            }
            // ������ �����
            if (syms[j].type == OUT_QWORD) {
                e.word_val = syms[j].word_val;
                e.type = OUT_WORD;
            }
            // ������ ������
            else {
                e.char_val = syms[j].char_val;
                e.type = OUT_CH;
            }
        }
        else {
            // ������������ ����� �����
            throw (new texception("exe_pop: internal error", 0, e.pos));
        }
    }
    int char_asc(int a) {
        if (a < 0) {
            a = a + 128 * 2;
        }
        return a;
    }
};