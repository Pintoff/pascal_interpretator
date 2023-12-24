#pragma once
// types.h
// ����������� ���� ������

#define ID_SIZE 63
#define MAX_COMSIZE 500
#define WORD_SIZE 65535
#define TFLOW_SIZE 100
#define MPSTACK_SIZE 64
#define MAX_SYMS 16
#define MAX_EXEST 64
#define MAX_STRIP 64
#define MAX_LABEL 16
#define MAX_IT 999
#define ST_EXISTS -2 // ������� ����������� (���� ��������)
#define ST_NOTFOUND -3 // // ������� ���������� (���� ��������)
#include <cstdio>
#include <string.h>
#include <stdio.h>



// ����������
struct texception {
    // ����������� (���� ��������)
    int def = 0;
    // �������
    int line = 0;
    // ���������
    char error[250] = { '\0' };
    texception(const char error[], int def, int line) {
        int len = strlen(error);
        this->def = def;
        this->line = line;;
        for (int i = 0; i < len; i++) {
            this->error[i] = error[i];
        }
    }
    void get_info(FILE* result) {
        if (def != 0) {
            printf("%s def: %d line: %d\n\n", error, def, line);
            fprintf(result, "%s def: %d line: %d\n\n", error, def, line);
            return;
        }
        printf("%s line: %d\n", error, line);
        fprintf(result, "%s line: %d\n", error, line);
    }
};

// ���� �������
enum ttype {
    OUT_START = 997,
    TOK_COMMENT,
    TOK_UNKNOWN,
    // ������
    TOK_EOT = 0,
    TOK_PROGRAM,
    TOK_ID,
    TOK_SEMI,
    TOK_VAR,
    TOK_COLON,
    TOK_COMMA,
    TOK_QWORD,
    TOK_QCH,
    TOK_BEGIN,
    TOK_END,
    TOK_ASS,
    TOK_IF,
    TOK_THEN,
    TOK_WRITE,
    TOK_EQ,
    TOK_NE,
    TOK_LT, //<
    TOK_GT, //>
    TOK_LE, //<=
    TOK_GE, //>=
    TOK_QOR,
    TOK_QAND,
    TOK_QNE,
    TOK_ADD,
    TOK_SUB,
    TOK_MUL,
    TOK_DIV,
    TOK_WORD,
    TOK_CH,
    TOK_LP,
    TOK_RP,
    TOK_LAST = TOK_RP,
    // �����������
    SYM_M,
    SYM_DS,
    SYM_SS,
    SYM_L_,
    SYM_V,
    SYM_D,
    SYM_D_,
    SYM_DD_,
    SYM_TP,
    SYM_G,
    SYM_S,
    SYM_S_,
    SYM_E,
    SYM_P,
    SYM_R,
    SYM_R_,
    SYM_LOR,
    SYM_LOR_,
    SYM_LAND,
    SYM_LAND_,
    SYM_LNOT,
    SYM_T,
    SYM_T_,
    SYM_U,
    SYM_U_,
    SYM_LAST = SYM_U_,
    // ����� �������� ����������
    TOK_LF,
    OUT_END,
    OUT_ID,
    OUT_QWORD,
    OUT_QCH,
    OUT_DIM,
    OUT_ASS,
    OUT_WORD,
    OUT_CH,
    OUT_EQ,
    OUT_NE,
    OUT_LT,
    OUT_GT,
    OUT_LE,
    OUT_GE,
    OUT_QOR,
    OUT_QAND,
    OUT_QNE,
    OUT_ADD,
    OUT_SUB,
    OUT_MUL,
    OUT_DIV,
    OUT_WRITE,
    OUT_LABEL,
    OUT_DEFL,
    OUT_PUSH,
    OUT_BZ,
    OUT_POPL,
    OUT_BOOL,
    OUT_PROGRAM
};

//������
struct tstring {
    char str[ID_SIZE];
    int set_str(const char val[]) {
        reset();
        int len = strlen(val);
        if (len > ID_SIZE) {
            return 0;
        }
        for (int i = 0; i < strlen(val); i++) {
            str[i] = val[i];
        }
        return 1;
    }
    void reset() {
        for (int i = 0; i < ID_SIZE; i++) {
            str[i] = '\0';
        }
    }
};

// �����
struct ttoken {
    // ������
    int pos;
    // ������������� ��������
    int word_val;
    // ���������� ��������
    char char_val;
    // ��������� ��������
    tstring str_val;
    // ���������� ������
    tstring tok_val;
    // ���
    ttype type;
    ttoken() {
        reset();
    }
    // ��������
    void reset() {
        pos = 0;
        word_val = 0;
        type = TOK_UNKNOWN;
        char_val = '\0';
        str_val.reset();
        tok_val.reset();
    }
    void show(int i, FILE* output) {
        fprintf(output, "\nToken %d: type %s, word_value %d, char_value %c, str_value %s, line %d", i, tok_val.str, word_val, char_val, str_val.str, pos);
    }
};

// ������ �������
struct tflow {
    // ������ ���������
    ttoken st[TFLOW_SIZE];
    // �������
    int count;
    // �������� �������
    int line;
    tflow() {
        count = 0;
        line = 1;
    }
    // �����������
    int push(ttype t, int word_val, char char_val, char* str_val, const char tok_val[]) {
        // ������������
        if (count >= TFLOW_SIZE) throw (new texception("tflow: Imposibble to add token", 0, get_pos()));
        st[count].type = t;
        // int_val
        if (t == TOK_WORD) st[count].word_val = word_val;
        // char_val
        if (t == TOK_CH) st[count].char_val = char_val;
        // str_val
        if (str_val) st[count].str_val.set_str(str_val);
        // tok_val
        st[count].tok_val.set_str(tok_val);
        if (t == TOK_LF) line++;
        // pos
        st[count].pos = line;
        count++;
        return 1;
    }
    int get_pos() {
        return line;
    }
    // ��������
    void reset() {
        for (int i = 0; i < count; i++) {
            st[i].reset();
        }
        count = 0;
        line = 1;
    }
    // �������
    void show(FILE* output) {
        for (int i = 0; i < count; i++) {
            st[i].show(i, output);
        }
    }
};



// ������� ��������
class stsyms {
private:
    // ������� ��������
    ttoken st[MAX_SYMS];
    // �������
    int count;
public:
    // �����������
    stsyms() {
        count = 0;
    }
    // ����������
    ~stsyms() {
        printf("stsyms: count=%d, size=%d\n", count, MAX_SYMS);
    }
    // ���������� ���������� ���������
    int size(void) {
        return count;
    }
    // ���������� ����� ������� � �������
    int find(ttoken tok) {
        for (int i = 0; i < count; i++) {
            if (strcmp(tok.str_val.str, st[i].str_val.str) == 0) {
                return i;
            }
        }
        return ST_NOTFOUND;
    }
    // ��������� ������ � �������
    int insert(ttoken tok) {
        if (count >= MAX_SYMS) throw (new texception("stsyms: insert table overflow", 0, 0));
        if (find(tok) == ST_NOTFOUND) {
            // ���������� ��� ���������� �� ����������������
            tok.tok_val.set_str("NON_INIT");
            st[count++] = tok;
            return count - 1;
        }
        else {
            return ST_EXISTS;
        }
    }
    // ���������� ������
    ttoken& operator [] (int index) {
        if (index < 0 || index > count) throw (new texception("stsyms: operator[] invalid index", 0, 0));
        return st[index];
    }
};


// ���� ��-��������
struct mpstack {
    // ������ ���������
    ttype st[MPSTACK_SIZE];
    // �������
    int count;
    // �����������
    mpstack() {
        reset();
    }
    // ���������� ���������� ���������
    int size(void) {
        return count;
    }
    // ��������
    void reset() {
        count = 0;
        for (int i = 0; i < MPSTACK_SIZE; i++) st[i] = TOK_EOT;
    }
    // �����������
    void push(ttype value) {
        if (count >= MPSTACK_SIZE) throw (new texception("ststack: push stack overflow", 0, 0));
        st[count++] = value;
    }
    // ����������
    ttype pop() {
        if (count < 1) throw (new texception("ststack: pop stack is empty", 0, 0));
        ttype value = st[count - 1];
        st[count - 1] = TOK_EOT;
        count--;
        return value;
    }
    // ����������� number ���������
    ttype pop(int number) {
        if (count < number) throw (new texception("ststack: pop(int) stack isn't so big as number", 0, 0));
        count -= number;
        return st[count];
    }
    // ���������� ������� �� �������
    ttype top(void) {
        if (count < 1) throw (new texception("ststack: top stack is empty", 0, 0));
        return st[count - 1];
    }
};

//
// ����������� ����
class exstack {
private:
    // ������ ���������
    ttoken st[MAX_EXEST];
    // �������
    int count;
    // �������
    int depth;
public:
    // �����������
    exstack() {
        count = 0;
        depth = 0;
    }
    // ����������
    ~exstack() {
        printf("exstack: size=%d, depth=%d.\n", MAX_EXEST, depth);
    }
    // ���������� ���������� ���������
    int size(void) {
        return count;
    }
    // ������������ �������
    void push(ttoken& e) {
        if (count >= MAX_EXEST) throw (new texception("exstack: push exe-stack overflow", 0, 0));
        st[count++] = e;
        if (depth < count) {
            depth = count;
        }
    }
    // ����������� �������
    void pop(ttoken& e) {
        if (count < 1) throw (new texception("exstack: pop exe-stack is empty", 0, 0));
        e = st[--count];
        st[count].reset();
    }
};


// ����� �����
class ststrip {
    // ������ ���������
    ttoken st[MAX_STRIP];
    // ������� ���������
    int count;
    // ������� �����
    int label;
    // �������
    int depth;
public:
    // �����������
    ststrip() {
        reset();
        st[0].type = OUT_START;
    }
    // ����������
    ~ststrip() {
        printf("ststrip: size=%d, depth=%d.\n", MAX_STRIP, depth - 1);
    }
    // ������� ������
    void reset(void) {
        count = 1;
        depth = label = 0;
        for (int i = 0; i < MAX_STRIP; i++) st[i].reset();
    }
    // ���������� ���������� ���������
    int size(void) {
        return count - 1;
    }
    // ���������� ����� ������������� �����
    int new_label() {
        return ++label;
    }
    // ���������� ��������� �������
    ttoken& operator [] (int index) {
        if (index < 1 || index >= count) throw (new texception("ststrip:operator[] invalid index", 0, 0));
        return st[index];
    }
    // ��������� �������
    void add(ttoken e) {
        if (count >= MAX_STRIP) throw (new texception("ststrip: add strip overflow", 0, 0));
        st[count++] = e;
        if (depth < count) depth = count;
    }
    // ���� �� ����� ����������� ����� � ��������������� id
    int find_DEF(int id) {
        for (int i = 1; i < count; i++) {
            if (st[i].type == OUT_END) return -1; // ����� �����
            if (st[i].type == OUT_LABEL && st[i].word_val == id) {
                if (st[i + 1].type == OUT_DEFL) {
                    return (i + 2);
                }
            }
        }
        return -1;
    }
    // ����� � ��������� ����
    void fprint(FILE* f) {
        fprintf(f, "\n");
        for (int i = 1; i < count; i++) {
            fprintf(f, "%03d ", i);
            switch (st[i].type) {
            case OUT_ID:    fprintf(f, "ID %s\n", st[i].str_val.str); break;
            case OUT_WORD:  fprintf(f, "WORD %d\n", st[i].word_val); break;
            case OUT_CH:    fprintf(f, "CHAR %c\n", st[i].char_val); break;
            case OUT_LABEL: fprintf(f, "LABEL %d\n", st[i].word_val); break;
            case OUT_DEFL:  fprintf(f, "DEFL\n"); break;
            case OUT_PUSH:  fprintf(f, "PUSH\n"); break;
            case OUT_POPL:  fprintf(f, "POPL\n"); break;
            case OUT_BZ:    fprintf(f, "BZ\n"); break;
            case OUT_EQ:    fprintf(f, "EQ\n"); break;
            case OUT_NE:    fprintf(f, "NE\n"); break;
            case OUT_LT:    fprintf(f, "LT\n"); break;
            case OUT_GT:    fprintf(f, "GT\n"); break;
            case OUT_LE:    fprintf(f, "LE\n"); break;
            case OUT_GE:    fprintf(f, "GE\n"); break;
            case OUT_QAND:  fprintf(f, "AND\n"); break;
            case OUT_QOR:   fprintf(f, "OR\n"); break;
            case OUT_QNE:   fprintf(f, "QNE\n"); break;
            case OUT_ADD:   fprintf(f, "ADD\n"); break;
            case OUT_SUB:   fprintf(f, "SUB\n"); break;
            case OUT_MUL:   fprintf(f, "MUL\n"); break;
            case OUT_DIV:   fprintf(f, "DIV\n"); break;
            case OUT_WRITE: fprintf(f, "WRITE\n"); break;
            case OUT_ASS:   fprintf(f, "ASS\n"); break;
            case OUT_DIM:   fprintf(f, "DIM\n"); break;
            case OUT_QWORD: fprintf(f, "QWORD\n"); break;
            case OUT_QCH:   fprintf(f, "QCHAR\n"); break;
            case OUT_END:   fprintf(f, "END\n"); break;
            case OUT_PROGRAM: fprintf(f, "PROGRAM\n"); break;
            default: fprintf(f, "UNKNOWN\n");
            }
        }
        fprintf(f, "\n");
    }
    // ����� � �������
    void print() {
        printf("\n");
        for (int i = 1; i < count; i++) {
            printf("%03d ", i);
            switch (st[i].type) {
            case OUT_ID:    printf("ID %s\n", st[i].str_val.str); break;
            case OUT_WORD:  printf("WORD %d\n", st[i].word_val); break;
            case OUT_CH:    printf("CHAR %c\n", st[i].char_val); break;
            case OUT_LABEL: printf("LABEL %d\n", st[i].word_val); break;
            case OUT_DEFL:  printf("DEFL\n"); break;
            case OUT_PUSH:  printf("PUSH\n"); break;
            case OUT_POPL:  printf("POPL\n"); break;
            case OUT_BZ:    printf("BZ\n"); break;
            case OUT_EQ:    printf("EQ\n"); break;
            case OUT_NE:    printf("NE\n"); break;
            case OUT_LT:    printf("LT\n"); break;
            case OUT_GT:    printf("GT\n"); break;
            case OUT_LE:    printf("LE\n"); break;
            case OUT_GE:    printf("GE\n"); break;
            case OUT_QAND:  printf("AND\n"); break;
            case OUT_QOR:   printf("OR\n"); break;
            case OUT_QNE:   printf("QNE\n"); break;
            case OUT_ADD:   printf("ADD\n"); break;
            case OUT_SUB:   printf("SUB\n"); break;
            case OUT_MUL:   printf("MUL\n"); break;
            case OUT_DIV:   printf("DIV\n"); break;
            case OUT_WRITE: printf("WRITE\n"); break;
            case OUT_ASS:   printf("ASS\n"); break;
            case OUT_DIM:   printf("DIM\n"); break;
            case OUT_QWORD: printf("QWORD\n"); break;
            case OUT_QCH:   printf("QCHAR\n"); break;
            case OUT_END:   printf("END\n"); break;
            case OUT_PROGRAM: printf("PROGRAM %s\n", st[i].str_val); break;
            default: printf("UNKNOWN\n");
            }
        }
    }
};

// ���� �����
class labelstack {
    // ������ ���������
    int st[MAX_LABEL];
    // �������
    int count;
    // �������
    int depth;
public:
    // �����������
    labelstack() {
        reset();
    }
    // ����������
    ~labelstack() {
        printf("labelstack: size=%d, depth=%d.\n", MAX_LABEL, depth);
    }
    // ������� ������
    void reset(void) {
        depth = count = 0;
        for (int i = 0; i < MAX_LABEL; i++) st[i] = 0;
    }
    // ���������� ���������� ���������
    int size(void) {
        return count;
    }
    // ������������ �������
    void push(int value) {
        if (count >= MAX_LABEL) throw (new texception("labelstack: push stack overflow", 0, 0));
        st[count++] = value;
        if (depth < count) depth = count;
    }
    // ����������� �������
    int pop(void) {
        if (count < 1) {
            throw (new texception("labelstack: pop stack is empty", 0, 0));
        }
        int value = st[--count];
        st[count] = 0;
        return value;
    }
    // ����������� number ���������
    int pop(int number) {
        if (count < number) throw (new texception("labelstack: pop(int) stack isn't so big as number", 0, 0));
        count -= number;
        return st[count];
    }
    // ���������� ������� �� �������
    int top(void) {
        if (count < 1) throw (new texception("labelstack: top stack is empty", 0, 0));
        return st[count - 1];
    }
};