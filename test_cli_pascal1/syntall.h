#pragma once
#include "types.h"
/* Generated by 2016 ReVoL SYNAX */
/* 27-11-2023 17:06:02 */

#define ST_MAX_RULE_LEN 16 /* Max rule length */

/* Rules */
ttype RULE[51][ST_MAX_RULE_LEN] = {
    /* 0*/{ TOK_EOT },
    /* 1 SYM_M     */{ SYM_DS, SYM_SS, TOK_EOT },
    /* 2 SYM_DS    */{ TOK_PROGRAM, TOK_ID, OUT_PROGRAM, TOK_SEMI, SYM_L_, TOK_EOT },
    /* 3 SYM_L_    */{ SYM_V, TOK_EOT },
    /* 4 SYM_L_    */{ TOK_EOT },
    /* 5 SYM_V     */{ TOK_VAR, SYM_D, SYM_D_, TOK_EOT },
    /* 6 SYM_D_    */{ SYM_D, SYM_D_, TOK_EOT },
    /* 7 SYM_D_    */{ TOK_EOT },
    /* 8 SYM_D     */{ TOK_ID, OUT_ID, SYM_DD_, TOK_COLON, SYM_TP, TOK_SEMI, OUT_DIM, TOK_EOT },
    /* 9 SYM_DD_   */{ TOK_COMMA, TOK_ID, OUT_ID, SYM_DD_, TOK_EOT },
    /*10 SYM_DD_   */{ TOK_EOT },
    /*11 SYM_TP    */{ TOK_QWORD, OUT_QWORD, TOK_EOT },
    /*12 SYM_TP    */{ TOK_QCH, OUT_QCH, TOK_EOT },
    /*13 SYM_SS    */{ TOK_BEGIN, SYM_G, TOK_END, TOK_EOT },
    /*14 SYM_G     */{ SYM_S, SYM_S_, TOK_EOT },
    /*15 SYM_S_    */{ SYM_S, SYM_S_, TOK_EOT },
    /*16 SYM_S_    */{ TOK_EOT },
    /*17 SYM_S     */{ TOK_SEMI, TOK_EOT },
    /*18 SYM_S     */{ TOK_ID, OUT_ID, TOK_ASS, SYM_E, OUT_ASS, TOK_SEMI, TOK_EOT },
    /*19 SYM_S     */{ TOK_IF, SYM_E, TOK_THEN, OUT_PUSH, OUT_BZ, SYM_S, OUT_POPL, OUT_DEFL, TOK_EOT },
    /*20 SYM_S     */{ TOK_WRITE, SYM_P, OUT_WRITE, TOK_SEMI, TOK_EOT },
    /*21 SYM_E     */{ SYM_R, SYM_R_, TOK_EOT },
    /*22 SYM_R_    */{ TOK_EQ, SYM_R, SYM_R_, OUT_EQ, TOK_EOT },
    /*23 SYM_R_    */{ TOK_NE, SYM_R, SYM_R_, OUT_NE, TOK_EOT },
    /*24 SYM_R_    */{ TOK_LT, SYM_R, SYM_R_, OUT_LT, TOK_EOT },
    /*25 SYM_R_    */{ TOK_GT, SYM_R, SYM_R_, OUT_GT, TOK_EOT },
    /*26 SYM_R_    */{ TOK_LE, SYM_R, SYM_R_, OUT_LE, TOK_EOT },
    /*27 SYM_R_    */{ TOK_GE, SYM_R, SYM_R_, OUT_GE, TOK_EOT },
    /*28 SYM_R_    */{ TOK_EOT },
    /*29 SYM_R     */{ SYM_LOR, SYM_LOR_, TOK_EOT },
    /*30 SYM_LOR_  */{ TOK_QOR, SYM_LOR, SYM_LOR_, OUT_QOR, TOK_EOT },
    /*31 SYM_LOR_  */{ TOK_EOT },
    /*32 SYM_LOR   */{ SYM_LAND, SYM_LAND_, TOK_EOT },
    /*33 SYM_LAND_ */{ TOK_QAND, SYM_LAND, SYM_LAND_, OUT_QAND,TOK_EOT },
    /*34 SYM_LAND_ */{ TOK_EOT },
    /*35 SYM_LAND  */{ SYM_LNOT, TOK_EOT },
    /*36 SYM_LNOT  */{ TOK_QNE, SYM_T, SYM_T_, OUT_QNE, TOK_EOT },
    /*37 SYM_LNOT  */{ SYM_T, SYM_T_, TOK_EOT },
    /*38 SYM_T_    */{ SYM_T, SYM_T_, TOK_EOT },
    /*39 SYM_T_    */{ TOK_ADD, SYM_T, SYM_T_, OUT_ADD, TOK_EOT },
    /*40 SYM_T_    */{ TOK_SUB, SYM_T, SYM_T_, OUT_SUB, TOK_EOT },
    /*41 SYM_T_    */{ TOK_EOT },
    /*42 SYM_T     */{ SYM_U, SYM_U_, TOK_EOT },
    /*43 SYM_U_    */{ TOK_MUL, SYM_U, SYM_U_, OUT_MUL, TOK_EOT },
    /*44 SYM_U_    */{ TOK_DIV, SYM_U, SYM_U_, OUT_DIV, TOK_EOT },
    /*45 SYM_U_    */{ TOK_EOT },
    /*46 SYM_U     */{ SYM_P, TOK_EOT },
    /*47 SYM_P     */{ TOK_WORD, OUT_WORD, TOK_EOT },
    /*48 SYM_P     */{ TOK_CH, OUT_CH, TOK_EOT },
    /*49 SYM_P     */{ TOK_ID, OUT_ID, TOK_EOT },
    /*50 SYM_P     */{ TOK_LP, SYM_E, TOK_RP, TOK_EOT }
};

#define MAX_RULE 50 /* Max rule index */

/* Rule Length */
//int RLEN[] = {0,2,4,1,0,3,2,0,5,3,0,1,1,3,2,2,0,1,4,4,3,2,3,3,3,3,3,3,0,2,3,0,2,3,0,1,3,2,2,3,3,0,2,3,3,0,1,1,1,1,3};
int RLEN[] = { 0,2,5,1,0,3,2,0,7,4,0, 2, 2, 3, 2, 2, 0, 1, 6, 8, 4, 2, 4, 4, 4, 4, 4, 4, 0, 2, 4, 0, 2, 4, 0, 1, 4, 2, 2, 4, 4, 0, 2, 4, 4, 0, 1, 2, 2, 2, 3 };
//////////////0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
/* Evaluates actual rule's length */
void get_rule_len() {
    int rule, count;
    for (rule = 1; rule <= MAX_RULE; rule++) {
        for (count = 0; count < ST_MAX_RULE_LEN; count++) {
            if ((int)RULE[rule][count] == 0) break;
        }
        RLEN[rule] = count;
    }
}

#define ACC 255 /* ACCEPT CODE */
#define POP 254 /* POP CODE */
#define START SYM_M /* START SYMBOL */

/* Syntax Table SYNTA (LL-analysis) */
int SYNTA[57][32] = {
    /*              EOT [PROG  [ID]   [;] [VAR]   [:]   [,] [QWOR [QCH] [BEGI [END]  [:=]  [if] [THEN [WRIT   [=]  [<>]   [<]   [>]  [<=]  [>=] [QOR] [QAND [QNE]   [+]   [-]   [*]   [/] [WORD  [CH]   [(]   [)] */
    /*         */{  ACC,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*[PROGRAM]*/{    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     [ID]*/{    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      [;]*/{    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*    [VAR]*/{    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      [:]*/{    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      [,]*/{    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*  [QWORD]*/{    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*    [QCH]*/{    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*  [BEGIN]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*    [END]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     [:=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     [if]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*   [THEN]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*  [WRITE]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      [=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     [<>]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      [<]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      [>]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     [<=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     [>=]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*    [QOR]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*   [QAND]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*    [QNE]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      [+]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0,    0 },
    /*      [-]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0,    0 },
    /*      [*]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0,    0 },
    /*      [/]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0,    0 },
    /*   [WORD]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0,    0 },
    /*     [CH]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0,    0 },
    /*      [(]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP,    0 },
    /*      [)]*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  POP },
    /*              EOT [PROG  [ID]   [;] [VAR]   [:]   [,] [QWOR [QCH] [BEGI [END]  [:=]  [if] [THEN [WRIT   [=]  [<>]   [<]   [>]  [<=]  [>=] [QOR] [QAND [QNE]   [+]   [-]   [*]   [/] [WORD  [CH]   [(]   [)] */
    /*      <M>*/{    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     <DS>*/{    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     <SS>*/{    0,    0,    0,    0,    0,    0,    0,    0,    0,   13,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     <L.>*/{    0,    0,    0,    0,    3,    0,    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      <V>*/{    0,    0,    0,    0,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      <D>*/{    0,    0,    8,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     <D.>*/{    0,    0,    6,    0,    0,    0,    0,    0,    0,    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*    <DD.>*/{    0,    0,    0,    0,    0,   10,    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     <TP>*/{    0,    0,    0,    0,    0,    0,    0,   11,   12,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      <G>*/{    0,    0,   14,   14,    0,    0,    0,    0,    0,    0,    0,    0,   14,    0,   14,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      <S>*/{    0,    0,   18,   17,    0,    0,    0,    0,    0,    0,    0,    0,   19,    0,   20,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*     <S.>*/{    0,    0,   15,   15,    0,    0,    0,    0,    0,    0,   16,    0,   15,    0,   15,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
    /*      <E>*/{    0,    0,   21,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   21,    0,    0,    0,    0,   21,   21,   21,    0 },
    /*      <P>*/{    0,    0,   49,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   47,   48,   50,    0 },
    /*      <R>*/{    0,    0,   29,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   29,    0,    0,    0,    0,   29,   29,   29,    0 },
    /*     <R.>*/{    0,    0,    0,   28,    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,    0,   22,   23,   24,   25,   26,   27,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   28 },
    /*    <LOR>*/{    0,    0,   32,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   32,    0,    0,    0,    0,   32,   32,   32,    0 },
    /*   <LOR.>*/{    0,    0,    0,   31,    0,    0,    0,    0,    0,    0,    0,    0,    0,   31,    0,   31,   31,   31,   31,   31,   31,   30,    0,    0,    0,    0,    0,    0,    0,    0,    0,   31 },
    /*   <LAND>*/{    0,    0,   35,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   35,    0,    0,    0,    0,   35,   35,   35,    0 },
    /*  <LAND.>*/{    0,    0,    0,   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,   34,    0,   34,   34,   34,   34,   34,   34,   34,   33,    0,    0,    0,    0,    0,    0,    0,    0,   34 },
    /*   <LNOT>*/{    0,    0,   37,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,    0,    0,    0,    0,   37,   37,   37,    0 },
    /*      <T>*/{    0,    0,   42,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   42,   42,   42,    0 },
    /*     <T.>*/{    0,    0,   38,   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,   41,    0,   41,   41,   41,   41,   41,   41,   41,   41,    0,   39,   40,    0,    0,   38,   38,   38,   41 },
    /*      <U>*/{    0,    0,   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   46,   46,   46,    0 },
    /*     <U.>*/{    0,    0,   45,   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,   45,    0,   45,   45,   45,   45,   45,   45,   45,   45,    0,   45,   45,   43,   44,   45,   45,   45,   45 }
};
