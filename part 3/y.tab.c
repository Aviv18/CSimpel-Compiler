/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 7 "proj.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "scope.h"


#define YYSTYPE struct node*
extern int yylex();
extern int yylineno;
extern char *yytext;

node* mknode(char* token,node* left,node* mid1,node* mid2, node* right);
void Printtree(node* tree,int tab);
int isTerminal(node* tree);
int AllChildTerminal(node* tree);
void yyerror(const char *msg);
char* freshVar();
char* freshLabel();
char* itoa(int value, char* result, int base);
int countSubString(char* source, char* find);
void printToFile(char* text);

scope* global;
int globalVar = -1;
int globalLabel = -1;
int countBeginFunc = 0;

#line 50 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define BOOL 257
#define VOID 258
#define CHAR 259
#define INT 260
#define STRING 261
#define INTP 262
#define CHARP 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define DO 267
#define FOR 268
#define RRETURN 269
#define NNULL 270
#define AND 271
#define DIVIDE 272
#define ASSIGN 273
#define ISEQUAL 274
#define GREATER 275
#define GREATEREQ 276
#define LESS 277
#define LESSEQ 278
#define MINUS 279
#define NOT 280
#define NOTEQUAL 281
#define OR 282
#define PLUS 283
#define MULT 284
#define BAND 285
#define BXOR 286
#define BOOL_TRUE 287
#define BOOL_FALSE 288
#define CHARR 289
#define NUM 290
#define ID 291
#define OCT 292
#define HEX 293
#define BIN 294
#define STRING_ID 295
#define SEMI 296
#define COMMA 297
#define ABS 298
#define OBRACE 299
#define CBRACE 300
#define OBRACKET 301
#define CBRACKET 302
#define OSQRERACKET 303
#define CSQRERACKET 304
#define OCMNT 305
#define CCMNT 306
#define SINMGLE_COMMENT 307
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    2,    2,    3,    3,    9,   10,   10,   10,
    6,    6,   14,   14,   15,   13,   13,   17,   17,   19,
   19,   16,   16,    4,    4,    4,    4,    4,   11,   11,
   11,   21,   21,   21,   21,    7,   26,   22,   22,   22,
   22,   27,   27,   23,   23,   24,   24,   24,   24,   25,
   25,   25,   25,   25,   30,   12,   12,   12,   29,   29,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   31,   31,   31,   31,    5,
   28,   32,    8,   18,   33,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    6,    6,    3,    2,    2,    0,
    1,    0,    3,    1,    2,    3,    3,    3,    1,    6,
    4,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    0,    1,    2,    1,    1,    3,    1,    4,    5,    8,
    5,    1,    4,    4,    3,    5,    7,    5,    7,    5,
    8,    5,    8,    7,    3,    3,    2,    0,    3,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    1,    1,    1,    1,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   24,   93,   25,   26,   27,   28,    0,    1,    2,    0,
    0,    0,    3,   90,    0,    0,    0,    0,   94,   22,
    0,    0,   14,    0,   23,    0,    0,    0,   15,    0,
    0,    5,   13,    6,    0,    0,    0,    0,    0,    0,
    8,    0,    0,   36,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   32,    0,   34,   35,    0,    9,
    0,    0,    0,   16,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   30,    0,    7,   29,   33,   91,    0,
    0,   17,    0,   18,   82,    0,    0,    0,   77,   78,
   92,   86,   87,   88,   89,   95,    0,    0,    0,   83,
   79,   76,   84,   85,    0,    0,    0,    0,    0,   45,
    0,    0,    0,   57,    0,    0,    0,    0,   73,   75,
   74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   44,   43,   56,    0,   38,    0,   81,   80,
    0,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   63,    0,   37,   48,   50,   52,    0,    0,   39,
   41,   59,    0,    0,    0,    0,    0,    0,    0,   20,
   47,   49,   54,    0,    0,    0,    0,   51,   53,   40,
};
static const YYINT yydgoto[] = {                          7,
    8,    9,   35,   20,   51,   21,   52,   12,   37,   38,
   53,   76,   39,   22,   23,   24,   43,   25,   62,  111,
  164,   55,  100,   57,   58,  165,  101,   80,  112,  178,
  102,  103,  104,
};
static const YYINT yysindex[] = {                       -82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -82,
 -277, -277,    0,    0, -284, -254,  -37,  -37,    0,    0,
 -247, -236,    0, -277,    0, -229, -234,  -37,    0, -234,
 -180,    0,    0,    0, -180, -277, -225,  -95, -180, -277,
    0, -289, -212,    0, -203, -200, -234, -197, -277, -277,
 -237,  -95, -184,  -95,    0, -190,    0,    0, -166,    0,
 -189, -181, -277,    0,  268,  268, -150, -158, -185, -166,
 -166,  215,  268,    0,  241,    0,    0,    0,    0,  294,
  268,    0, -174,    0,    0,  268, -277,  268,    0,    0,
    0,    0,    0,    0,    0,    0,  268,  268,  322,    0,
    0,    0,    0,    0,  336, -170,  268,  268,  268,    0,
  398, -173,   36,    0,  415, -277,  431,   50,    0,    0,
    0,  380,  351,  268,  268,  268,  268,  268,  268,  268,
  268,  268,  268,  268,  268,  -95,  -95,  268,  447,  463,
  479,  268,    0,    0,    0, -169,    0, -161,    0,    0,
  524,    0, -216, -216, -216, -216, -216, -253, -216,  524,
 -253,    0, -128,    0,    0,    0,    0,  365, -277,    0,
    0,    0,  268, -277,  -95, -156, -166, -160,   67,    0,
    0,    0,    0,  268,  -95, -153,  511,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  145,
    0,    0,    0,    0,    0,    0, -154, -154,    0,    0,
    0, -148,    0,    0,    0,    0,    0,    0,    0,    0,
 -147,    0,    0,    0, -147,    0,    0, -260, -147,    0,
    0, -141,    0,    0,    0,    0,    0,    0,    0,    0,
  -66, -260, -151, -260,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -117,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -141,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -143,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  495,    0, -135,    0,    0,
 -172,    0,   81,  113,  122,  154,  163,  -32,  195, -103,
    2,    0, -102,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -132,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  164,   11,   23,  -11,  167,  -25,    0,    0,   -3,
   20,    0,    0,    0,  158,    0,  119,   14,   13,  -38,
   -8,  120,  -28,    0,    0, -134,  -34,  -64,   58,    0,
    0,    0,    0,
};
#define YYTABLESIZE 808
static const YYINT yytable[] = {                         15,
   16,   32,  167,   59,   34,  108,  109,   63,   31,   56,
   10,   17,   29,   14,   70,   71,   17,   59,  125,   59,
   10,   67,   11,   56,   42,   56,   99,  105,   61,   54,
  135,   41,   11,   59,  113,   60,  115,   69,   69,   31,
  182,  117,  118,   54,   40,   54,   18,  119,   40,  121,
  189,   83,   40,   36,   27,  125,   69,   36,  122,  123,
   28,   36,  131,   72,   31,   73,  134,  135,  139,  140,
  141,   74,   30,   77,   44,  120,    1,    2,    3,    4,
   19,    5,    6,   64,   75,  151,  152,  153,  154,  155,
  156,  157,  158,  159,  160,  161,  162,   65,   65,  168,
   66,   59,   59,   68,  146,   78,   79,   56,   56,   65,
  163,  166,  184,   81,   82,  106,   10,   73,   10,   10,
   10,   10,   63,   65,   65,   65,   49,   50,  143,   65,
  138,   65,   14,  173,  179,  174,  175,   10,   10,  183,
   59,  185,  190,   10,    4,  187,   56,   12,   58,  181,
   59,   10,   10,   11,   19,   42,   56,  177,   60,  188,
   21,   46,   61,   46,   46,   46,   46,   66,   45,   55,
   46,   47,   48,   13,    1,    2,    3,    4,   66,    5,
    6,   84,   46,   46,   26,   33,  180,  107,   46,   49,
   50,    0,   66,   66,   66,   14,   46,   46,   66,  172,
   66,    0,    0,   31,   42,   42,   42,   42,   42,   42,
   42,   42,   42,    0,   42,   42,   42,   42,    0,    1,
    0,    3,    4,   19,    5,    6,    0,    0,    0,   42,
   42,   42,    0,    0,    0,   42,    0,   42,   62,    0,
    0,   62,   62,   62,   62,   62,   62,    0,   62,   62,
   62,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   62,   62,   62,    0,    0,    0,   62,
    0,   62,   61,    0,    0,   61,   61,   61,   61,   61,
   61,    0,   61,   61,   61,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   61,   61,   61,
    0,    0,    0,   61,    0,   61,  124,  125,    0,  126,
  127,  128,  129,  130,  131,    0,  132,  133,  134,  135,
  124,  125,    0,  126,  127,  128,  129,  130,  131,    0,
  132,  133,  134,  135,    0,    0,    0,  124,  125,  144,
  126,  127,  128,  129,  130,  131,    0,  132,  133,  134,
  135,   67,    0,  148,   67,   67,   67,   67,   67,    0,
    0,   67,   67,    0,    0,    0,    0,    0,    0,    0,
  186,    0,    0,    0,    0,    0,   67,   67,   67,    0,
    0,    0,   67,   69,   67,    0,   69,   69,   69,   69,
   69,    0,   70,   69,   69,   70,   70,   70,   70,   70,
    0,    0,   70,   70,    0,    0,    0,    0,   69,   69,
   69,    0,    0,    0,   69,    0,   69,   70,   70,   70,
    0,    0,    0,   70,   71,   70,    0,   71,   71,   71,
   71,   71,    0,   72,   71,   71,   72,   72,   72,   72,
   72,    0,    0,   72,   72,    0,    0,    0,    0,   71,
   71,   71,    0,    0,    0,   71,    0,   71,   72,   72,
   72,    0,    0,    0,   72,   68,   72,    0,   68,   68,
   68,   68,   68,    0,    0,   68,   68,    0,    0,    0,
    0,    0,    0,    0,   85,    0,    0,    0,    0,    0,
   68,   68,   68,    0,   86,    0,   68,    0,   68,   87,
   88,   89,   90,   91,   92,   14,   93,   94,   95,   96,
   85,    0,   97,    0,    0,   98,  110,    0,    0,    0,
   86,    0,    0,    0,    0,   87,   88,   89,   90,   91,
   92,   14,   93,   94,   95,   96,  114,   85,   97,    0,
    0,   98,    0,    0,    0,    0,    0,   86,    0,    0,
    0,    0,   87,   88,   89,   90,   91,   92,   14,   93,
   94,   95,   96,   85,    0,   97,    0,    0,   98,    0,
    0,    0,    0,   86,    0,    0,    0,    0,  116,   88,
   89,   90,   91,   92,   14,   93,   94,   95,   96,    0,
    0,   97,  124,  125,   98,  126,  127,  128,  129,  130,
  131,    0,  132,  133,  134,  135,  124,  125,    0,  126,
  127,  128,  129,  130,  131,    0,  132,  133,  134,  135,
    0,  124,  125,  136,  126,  127,  128,  129,  130,  131,
    0,  132,  133,  134,  135,  124,  125,  137,  126,  127,
  128,  129,  130,  131,    0,  132,  133,  134,  135,    0,
  124,  125,  150,  126,  127,  128,  129,  130,  131,    0,
  132,  133,  134,  135,    0,    0,  176,    0,  124,  125,
    0,  126,  127,  128,  129,  130,  131,  149,  132,  133,
  134,  135,    0,    0,    0,  124,  125,    0,  126,  127,
  128,  129,  130,  131,  142,  132,  133,  134,  135,    0,
    0,  124,  125,    0,  126,  127,  128,  129,  130,  131,
  145,  132,  133,  134,  135,    0,    0,  124,  125,    0,
  126,  127,  128,  129,  130,  131,  147,  132,  133,  134,
  135,    0,    0,  124,  125,    0,  126,  127,  128,  129,
  130,  131,  169,  132,  133,  134,  135,    0,    0,  124,
  125,    0,  126,  127,  128,  129,  130,  131,  170,  132,
  133,  134,  135,    0,    0,   75,   75,    0,   75,   75,
   75,   75,   75,   75,  171,   75,   75,   75,   75,    0,
    0,  124,  125,    0,  126,  127,  128,  129,  130,  131,
   75,  132,  133,  134,  135,  125,    0,  126,  127,  128,
  129,  130,  131,    0,  132,    0,  134,  135,
};
static const YYINT yycheck[] = {                         11,
   12,   27,  137,   38,   30,   70,   71,  297,  269,   38,
    0,  301,   24,  291,   49,   50,  301,   52,  272,   54,
   10,   47,    0,   52,   36,   54,   65,   66,   40,   38,
  284,   35,   10,   68,   73,   39,   75,   49,   50,  300,
  175,   80,   81,   52,   31,   54,  301,   86,   35,   88,
  185,   63,   39,   31,  302,  272,   68,   35,   97,   98,
  297,   39,  279,  301,  299,  303,  283,  284,  107,  108,
  109,   52,  302,   54,  300,   87,  257,  258,  259,  260,
  261,  262,  263,  296,  269,  124,  125,  126,  127,  128,
  129,  130,  131,  132,  133,  134,  135,  301,  271,  138,
  301,  136,  137,  301,  116,  296,  273,  136,  137,  282,
  136,  137,  177,  303,  296,  266,  264,  303,  266,  267,
  268,  269,  297,  296,  297,  298,  285,  286,  302,  302,
  301,  304,  291,  303,  173,  297,  265,  285,  286,  296,
  175,  302,  296,  291,    0,  184,  175,  302,  300,  175,
  185,  299,  300,  302,  296,  273,  185,  169,  302,  185,
  296,  264,  174,  266,  267,  268,  269,  271,  264,  302,
  266,  267,  268,   10,  257,  258,  259,  260,  282,  262,
  263,   63,  285,  286,   18,   28,  174,   68,  291,  285,
  286,   -1,  296,  297,  298,  291,  299,  300,  302,  142,
  304,   -1,   -1,  299,  271,  272,  273,  274,  275,  276,
  277,  278,  279,   -1,  281,  282,  283,  284,   -1,  257,
   -1,  259,  260,  261,  262,  263,   -1,   -1,   -1,  296,
  297,  298,   -1,   -1,   -1,  302,   -1,  304,  271,   -1,
   -1,  274,  275,  276,  277,  278,  279,   -1,  281,  282,
  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  296,  297,  298,   -1,   -1,   -1,  302,
   -1,  304,  271,   -1,   -1,  274,  275,  276,  277,  278,
  279,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  296,  297,  298,
   -1,   -1,   -1,  302,   -1,  304,  271,  272,   -1,  274,
  275,  276,  277,  278,  279,   -1,  281,  282,  283,  284,
  271,  272,   -1,  274,  275,  276,  277,  278,  279,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,  271,  272,  304,
  274,  275,  276,  277,  278,  279,   -1,  281,  282,  283,
  284,  271,   -1,  304,  274,  275,  276,  277,  278,   -1,
   -1,  281,  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  304,   -1,   -1,   -1,   -1,   -1,  296,  297,  298,   -1,
   -1,   -1,  302,  271,  304,   -1,  274,  275,  276,  277,
  278,   -1,  271,  281,  282,  274,  275,  276,  277,  278,
   -1,   -1,  281,  282,   -1,   -1,   -1,   -1,  296,  297,
  298,   -1,   -1,   -1,  302,   -1,  304,  296,  297,  298,
   -1,   -1,   -1,  302,  271,  304,   -1,  274,  275,  276,
  277,  278,   -1,  271,  281,  282,  274,  275,  276,  277,
  278,   -1,   -1,  281,  282,   -1,   -1,   -1,   -1,  296,
  297,  298,   -1,   -1,   -1,  302,   -1,  304,  296,  297,
  298,   -1,   -1,   -1,  302,  271,  304,   -1,  274,  275,
  276,  277,  278,   -1,   -1,  281,  282,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  270,   -1,   -1,   -1,   -1,   -1,
  296,  297,  298,   -1,  280,   -1,  302,   -1,  304,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  270,   -1,  298,   -1,   -1,  301,  302,   -1,   -1,   -1,
  280,   -1,   -1,   -1,   -1,  285,  286,  287,  288,  289,
  290,  291,  292,  293,  294,  295,  296,  270,  298,   -1,
   -1,  301,   -1,   -1,   -1,   -1,   -1,  280,   -1,   -1,
   -1,   -1,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  270,   -1,  298,   -1,   -1,  301,   -1,
   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,  295,   -1,
   -1,  298,  271,  272,  301,  274,  275,  276,  277,  278,
  279,   -1,  281,  282,  283,  284,  271,  272,   -1,  274,
  275,  276,  277,  278,  279,   -1,  281,  282,  283,  284,
   -1,  271,  272,  302,  274,  275,  276,  277,  278,  279,
   -1,  281,  282,  283,  284,  271,  272,  302,  274,  275,
  276,  277,  278,  279,   -1,  281,  282,  283,  284,   -1,
  271,  272,  302,  274,  275,  276,  277,  278,  279,   -1,
  281,  282,  283,  284,   -1,   -1,  302,   -1,  271,  272,
   -1,  274,  275,  276,  277,  278,  279,  298,  281,  282,
  283,  284,   -1,   -1,   -1,  271,  272,   -1,  274,  275,
  276,  277,  278,  279,  297,  281,  282,  283,  284,   -1,
   -1,  271,  272,   -1,  274,  275,  276,  277,  278,  279,
  296,  281,  282,  283,  284,   -1,   -1,  271,  272,   -1,
  274,  275,  276,  277,  278,  279,  296,  281,  282,  283,
  284,   -1,   -1,  271,  272,   -1,  274,  275,  276,  277,
  278,  279,  296,  281,  282,  283,  284,   -1,   -1,  271,
  272,   -1,  274,  275,  276,  277,  278,  279,  296,  281,
  282,  283,  284,   -1,   -1,  271,  272,   -1,  274,  275,
  276,  277,  278,  279,  296,  281,  282,  283,  284,   -1,
   -1,  271,  272,   -1,  274,  275,  276,  277,  278,  279,
  296,  281,  282,  283,  284,  272,   -1,  274,  275,  276,
  277,  278,  279,   -1,  281,   -1,  283,  284,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYUNDFTOKEN 343
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"BOOL","VOID","CHAR","INT",
"STRING","INTP","CHARP","IF","ELSE","WHILE","DO","FOR","RRETURN","NNULL","AND",
"DIVIDE","ASSIGN","ISEQUAL","GREATER","GREATEREQ","LESS","LESSEQ","MINUS","NOT",
"NOTEQUAL","OR","PLUS","MULT","BAND","BXOR","BOOL_TRUE","BOOL_FALSE","CHARR",
"NUM","ID","OCT","HEX","BIN","STRING_ID","SEMI","COMMA","ABS","OBRACE","CBRACE",
"OBRACKET","CBRACKET","OSQRERACKET","CSQRERACKET","OCMNT","CCMNT",
"SINMGLE_COMMENT",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : START",
"START : PROGRAM",
"PROGRAM : FUNCTIONS",
"FUNCTIONS : FUNCTION FUNCTIONS",
"FUNCTIONS : FUNCTION",
"FUNCTION : TYPE id OBRACKET F_PARAMS CBRACKET CODE_BLOCK",
"FUNCTION : void id OBRACKET F_PARAMS CBRACKET CODE_BLOCK",
"BODY : DECLERATIONS STATMENTS RETURN_STATMENT",
"DECLERATIONS : FUNCTION DECLERATIONS",
"DECLERATIONS : VAR_DECLERACTION DECLERATIONS",
"DECLERATIONS :",
"F_PARAMS : F_PARAMSS",
"F_PARAMS :",
"F_PARAMSS : F_PARAMSS COMMA PARAM",
"F_PARAMSS : PARAM",
"PARAM : PARAM_TYPE id",
"VAR_DECLERACTION : TYPE IDS SEMI",
"VAR_DECLERACTION : string SID SEMI",
"IDS : id COMMA IDS",
"IDS : id",
"SID : id OSQRERACKET EXPR CSQRERACKET COMMA SID",
"SID : id OSQRERACKET EXPR CSQRERACKET",
"PARAM_TYPE : TYPE",
"PARAM_TYPE : string",
"TYPE : BOOL",
"TYPE : CHAR",
"TYPE : INT",
"TYPE : INTP",
"TYPE : CHARP",
"STATMENTS : STATMENT STATMENTS",
"STATMENTS : CODE_BLOCK STATMENTS",
"STATMENTS :",
"STATMENT : ASSIGNMENT",
"STATMENT : FUNC_CALL SEMI",
"STATMENT : IFS",
"STATMENT : LOOPS",
"CODE_BLOCK : OBRACE BODY CBRACE",
"SINGLE_STATMENT : STATMENT",
"ASSIGNMENT : ASSIGNMENT_VAR assign EXPR SEMI",
"ASSIGNMENT : BAND ASSIGNMENT_VAR assign EXPR SEMI",
"ASSIGNMENT : ASSIGNMENT_VAR assign BAND id OSQRERACKET EXPR CSQRERACKET SEMI",
"ASSIGNMENT : BXOR ASSIGNMENT_VAR assign EXPR SEMI",
"ASSIGNMENT_VAR : id",
"ASSIGNMENT_VAR : id OSQRERACKET EXPR CSQRERACKET",
"FUNC_CALL : id OBRACKET EXPR_LIST CBRACKET",
"FUNC_CALL : id OBRACKET CBRACKET",
"IFS : IF OBRACKET EXPR CBRACKET CODE_BLOCK",
"IFS : IF OBRACKET EXPR CBRACKET CODE_BLOCK ELSE CODE_BLOCK",
"IFS : IF OBRACKET EXPR CBRACKET SINGLE_STATMENT",
"IFS : IF OBRACKET EXPR CBRACKET CODE_BLOCK ELSE SINGLE_STATMENT",
"LOOPS : WHILE OBRACKET EXPR CBRACKET CODE_BLOCK",
"LOOPS : FOR OBRACKET ASSIGNMENT EXPR SEMI UPDATES CBRACKET CODE_BLOCK",
"LOOPS : WHILE OBRACKET EXPR CBRACKET SINGLE_STATMENT",
"LOOPS : FOR OBRACKET ASSIGNMENT EXPR SEMI UPDATES CBRACKET SINGLE_STATMENT",
"LOOPS : DO CODE_BLOCK WHILE OBRACKET EXPR CBRACKET SEMI",
"UPDATES : id assign EXPR",
"RETURN_STATMENT : RRETURN EXPR SEMI",
"RETURN_STATMENT : RRETURN SEMI",
"RETURN_STATMENT :",
"EXPR_LIST : EXPR COMMA EXPR_LIST",
"EXPR_LIST : EXPR",
"EXPR : EXPR PLUS EXPR",
"EXPR : EXPR MINUS EXPR",
"EXPR : EXPR MULT EXPR",
"EXPR : EXPR DIVIDE EXPR",
"EXPR : EXPR AND EXPR",
"EXPR : EXPR OR EXPR",
"EXPR : EXPR ISEQUAL EXPR",
"EXPR : EXPR NOTEQUAL EXPR",
"EXPR : EXPR GREATER EXPR",
"EXPR : EXPR GREATEREQ EXPR",
"EXPR : EXPR LESS EXPR",
"EXPR : EXPR LESSEQ EXPR",
"EXPR : NOT EXPR",
"EXPR : BXOR EXPR",
"EXPR : BAND id",
"EXPR : NUMS",
"EXPR : BOOL_TRUE",
"EXPR : BOOL_FALSE",
"EXPR : ASSIGNMENT_VAR",
"EXPR : OBRACKET EXPR CBRACKET",
"EXPR : ABS EXPR ABS",
"EXPR : NNULL",
"EXPR : FUNC_CALL",
"EXPR : char",
"EXPR : string_id",
"NUMS : NUM",
"NUMS : OCT",
"NUMS : HEX",
"NUMS : BIN",
"id : ID",
"assign : ASSIGN",
"char : CHARR",
"void : VOID",
"string : STRING",
"string_id : STRING_ID",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 779 "proj.y"

#include "lex.yy.c"

char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}

void main(){
	global=initGlobalScope();
    yyparse();
}

// char* freshVar1(char* code){
// 	globalVar++;
// 	char strNum[10];
// 	itoa(globalVar,strNum, 10);
// 	char *t = (char*)malloc(sizeof(char)*10);
// 	strcpy(t, "t");
// 	strcat(t, strNum);
// 	return t;
// }

char* freshVar(){
	globalVar++;
	countBeginFunc+=4;
	char strNum[10];
	itoa(globalVar,strNum, 10);
	char *t = (char*)malloc(sizeof(char)*10);
	strcpy(t, "t");
	strcat(t, strNum);
	return t;
}

char* freshLabel(){
	globalLabel++;
	char strNum[10];
	itoa(globalLabel,strNum, 10);
	char *t = (char*)malloc(sizeof(char)*10);
	strcpy(t, "L");
	strcat(t, strNum);
	return t;
}

char* convertToTacFormat(char *str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]=='\n' && str[i+1]=='#')
		  	str[i+1]='\t';
		
		i=i+1;
	}
	return str;
}

void yyerror(const char *msg)
{
	fflush(stdout);
	fprintf(stderr, "Error: %s at line %d\n", msg,yylineno);
	fprintf(stderr, "Parser does not expect '%s'\n",yytext);
}

int countPushParams(char* code)
{
	int i=0, count, countReduce = 0, numToReduce = 0;
	char strToReduce[5];
	count=countSubString(code, "PushParams")*4;
	
	if (code)
	{
		while(code[i] != '\0')
		{
			if(code[i+1] == 'P' && code[i+2] == 'o')
			{
				i+=11;
				while(code[i] != '\n')
				{
					strToReduce[countReduce] = code[i];
					countReduce++;
					i++;
				}
				
				strToReduce[countReduce] = '\0';
				numToReduce = atoi(strToReduce);
				count -= numToReduce;
				
			}
			countReduce = 0;

			while(code[i]!='\n')
			{	
				i++;
			}
			i++;
		}
	}
	return count;
}

int countSubString(char* source, char* find){
	int count = 0;
	const char *tmp = source;
	while(tmp = strstr(tmp, find))
	{
   		count++;
   		tmp++;
	}
	return count;
}

void printToFile(char *text){
	FILE *fptr;
	fptr = fopen("TAC.txt", "w");
   	if(fptr == NULL)
   	{
      printf("Can't open file!\n");
      exit(1);
   	}
	fprintf(fptr,"%s", text);
   	fclose(fptr);
}


#line 710 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 63 "proj.y"
	{/*pre($1,0);*/scanTree(yystack.l_mark[0]->left,&global);checkMainOnce();
						/*printf("\n\n\n****SCOPES****\n\n");	printSymbolTable(global,0);*/
						printf("OK\nTac printed to file\n");
						printToFile(yyval->code);
						/*printf("%s\n",$$->code);*/
						}
break;
case 2:
#line 73 "proj.y"
	{
						
						yyval=mknode("PROGRAM",yystack.l_mark[0],NULL ,NULL,NULL);
						strcat(yyval->code,yystack.l_mark[0]->code);	
						}
break;
case 3:
#line 81 "proj.y"
	{
						
						yyval=mknode("FUNC_NODE",yystack.l_mark[-1],yystack.l_mark[0],NULL,NULL);
						strcat(yyval->code,yystack.l_mark[-1]->code);	
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[0]->code);	

						}
break;
case 4:
#line 89 "proj.y"
	{
							yyval=mknode("FUNC_NODE",yystack.l_mark[0],NULL,NULL,NULL);
							strcat(yyval->code,yystack.l_mark[0]->code);	
						}
break;
case 5:
#line 98 "proj.y"
	{
						char num[33];
						
						yyval=mknode("FUNCTION",yystack.l_mark[-5],yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0]);
							strcat(yyval->code,yystack.l_mark[-4]->token);
							strcat(yyval->code,":\nBeginFunc ");
							strcat(yyval->code,itoa(countBeginFunc,num,10));
							strcat(yyval->code,";\n");
							strcat(yyval->code,yystack.l_mark[0]->code);	
							strcat(yyval->code,"\nEndFunc;");	
							countBeginFunc=0;
							globalVar=-1;
							globalLabel=-1;		
						}
break;
case 6:
#line 113 "proj.y"
	{
						char num[33];
						yyval=mknode("FUNCTION",yystack.l_mark[-5],yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0]);

							strcat(yyval->code,yystack.l_mark[-4]->token);
							strcat(yyval->code,":\nBeginFunc ");
							strcat(yyval->code,itoa(countBeginFunc,num,10));
							strcat(yyval->code,";\n");
							strcat(yyval->code,yystack.l_mark[0]->code);
							strcat(yyval->code,"\nEndFunc;");
							countBeginFunc=0;
							globalVar=-1;
							globalLabel=-1;
											
						}
break;
case 7:
#line 130 "proj.y"
	{

						yyval=mknode("BODY",yystack.l_mark[-2],yystack.l_mark[-1],yystack.l_mark[0],NULL);
						if(yystack.l_mark[-1]!=NULL)
							strcat(yyval->code,yystack.l_mark[-1]->code);
						if(yystack.l_mark[0] != NULL)
							strcat(yyval->code, yystack.l_mark[0]->code);
						}
break;
case 8:
#line 140 "proj.y"
	{yyval=mknode("DECLARATIONS",yystack.l_mark[-1],yystack.l_mark[0],NULL,NULL);}
break;
case 9:
#line 141 "proj.y"
	{yyval=mknode("DECLARATIONS",yystack.l_mark[-1],yystack.l_mark[0],NULL,NULL);}
break;
case 11:
#line 149 "proj.y"
	{yyval=yystack.l_mark[0];}
break;
case 13:
#line 153 "proj.y"
	{yyval=mknode("FPARAM",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);}
break;
case 14:
#line 154 "proj.y"
	{yyval=mknode("FPARAM",NULL,yystack.l_mark[0],NULL,NULL);}
break;
case 15:
#line 160 "proj.y"
	{yyval=mknode(yystack.l_mark[-1]->token,yystack.l_mark[0],NULL,NULL,NULL);}
break;
case 16:
#line 164 "proj.y"
	{yyval=mknode("IDS",yystack.l_mark[-2],yystack.l_mark[-1],NULL,NULL);}
break;
case 17:
#line 165 "proj.y"
	{yyval=mknode("IDS",yystack.l_mark[-2],yystack.l_mark[-1],NULL,NULL);}
break;
case 18:
#line 168 "proj.y"
	{yyval=mknode("ID",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);countBeginFunc+=4;}
break;
case 19:
#line 169 "proj.y"
	{yyval=mknode("ID",yystack.l_mark[0],NULL,NULL,NULL);countBeginFunc+=4;}
break;
case 20:
#line 172 "proj.y"
	{yyval=mknode("ID",yystack.l_mark[-5],yystack.l_mark[0],mknode("SIZE",yystack.l_mark[-3],NULL,NULL,NULL),NULL);countBeginFunc+=4;}
break;
case 21:
#line 173 "proj.y"
	{yyval=mknode("ID",yystack.l_mark[-3],NULL,mknode("SIZE",yystack.l_mark[-1],NULL,NULL,NULL),NULL);countBeginFunc+=4;}
break;
case 22:
#line 176 "proj.y"
	{yyval=yystack.l_mark[0];}
break;
case 23:
#line 177 "proj.y"
	{yyval=yystack.l_mark[0];}
break;
case 24:
#line 180 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 25:
#line 181 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 26:
#line 182 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 27:
#line 183 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 28:
#line 184 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 29:
#line 188 "proj.y"
	{

						yyval=mknode("STATMENT_NODE",yystack.l_mark[-1],yystack.l_mark[0],NULL,NULL);
						strcat(yyval->code,yystack.l_mark[-1]->code);
						strcat(yyval->code,"\n");
						if(yystack.l_mark[0]!=NULL)
							strcat(yyval->code,yystack.l_mark[0]->code);
						}
break;
case 30:
#line 196 "proj.y"
	{
						yyval=mknode("STATMENT_NODE",yystack.l_mark[-1],yystack.l_mark[0],NULL,NULL);
						}
break;
case 32:
#line 202 "proj.y"
	{yyval=yystack.l_mark[0];}
break;
case 33:
#line 203 "proj.y"
	{yyval=yystack.l_mark[-1];}
break;
case 34:
#line 204 "proj.y"
	{yyval=yystack.l_mark[0];}
break;
case 35:
#line 205 "proj.y"
	{yyval=yystack.l_mark[0];}
break;
case 36:
#line 208 "proj.y"
	{yyval=yystack.l_mark[-1];}
break;
case 37:
#line 211 "proj.y"
	{
						yyval=mknode("BODY",mknode("STATMENT_NODE",yystack.l_mark[0],NULL,NULL,NULL),NULL,NULL,NULL);
						yyval->code=yystack.l_mark[0]->code;
						}
break;
case 38:
#line 217 "proj.y"
	{
						yyval=mknode(yystack.l_mark[-2]->token,yystack.l_mark[-3],yystack.l_mark[-1],NULL,NULL);
						strcat(yyval->code, yystack.l_mark[-3]->code);
						strcat(yyval->code,yystack.l_mark[-1]->code);
						strcat(yyval->code,"\t");
						strcat(yyval->code,yystack.l_mark[-3]->var);
						strcat(yyval->code,":=");
						strcat(yyval->code,yystack.l_mark[-1]->var);
						}
break;
case 39:
#line 226 "proj.y"
	{
							yyval=mknode(yystack.l_mark[-2]->token,mknode("&",yystack.l_mark[-3],NULL,NULL,NULL),yystack.l_mark[-1],NULL,NULL);
							strcat(yyval->code, yystack.l_mark[-3]->code);
							strcat(yyval->code,yystack.l_mark[-1]->code);
							strcat(yyval->code,"\t");
							strcat(yyval->code,yystack.l_mark[-3]->var);
							strcat(yyval->code,":=");
							strcat(yyval->code,yystack.l_mark[-1]->var);
						}
break;
case 40:
#line 235 "proj.y"
	{
						
							yyval=mknode(yystack.l_mark[-6]->token,yystack.l_mark[-7],mknode("&",yystack.l_mark[-4],NULL,mknode("SIZE",yystack.l_mark[-2],NULL,NULL,NULL),NULL),NULL,NULL);

							char tempFreshVar1[10], tempFreshVar2[10],*tmp=(char*)malloc(sizeof(char)*100000);
							strcpy(tempFreshVar1, freshVar());
							strcat(tmp, yystack.l_mark[-2]->code);
							strcat(tmp, "\t");
							strcat(tmp, tempFreshVar1);
							strcat(tmp, ":=");
							strcat(tmp, yystack.l_mark[-2]->var);
							strcat(tmp, "\t\n\t");
							strcpy(tempFreshVar2, freshVar());
							strcat(tmp, tempFreshVar2);
							strcat(tmp, ":=4*");
							strcat(tmp, tempFreshVar1);
							strcat(tmp, "\n\t");
							strcpy(tempFreshVar1, freshVar());
							strcat(tmp, tempFreshVar1);
							strcat(tmp, ":=");
							strcat(tmp, yystack.l_mark[-4]->token);
							strcat(tmp, "+");
							
							strcat(tmp, tempFreshVar2);
							strcat(tmp, "\n");

							strcat(yyval->code, yystack.l_mark[-7]->code);
							strcat(yyval->code,tmp);
							strcat(yyval->code,"\t");
							strcat(yyval->code,yystack.l_mark[-7]->var);
							strcat(yyval->code,":=");
							strcat(yyval->code,yystack.l_mark[-2]->var);
							
						}
break;
case 41:
#line 269 "proj.y"
	{
							
							yyval=mknode(yystack.l_mark[-2]->token,mknode("^",yystack.l_mark[-3],NULL,NULL,NULL),yystack.l_mark[-1],NULL,NULL);
							strcat(yyval->code, yystack.l_mark[-3]->code);
							strcat(yyval->code,yystack.l_mark[-1]->code);
							strcat(yyval->code,"\t");
							strcat(yyval->code,yystack.l_mark[-3]->var);
							strcat(yyval->code,":=");
							strcat(yyval->code,yystack.l_mark[-1]->var);
						}
break;
case 43:
#line 282 "proj.y"
	{
							yyval=mknode(yystack.l_mark[-3]->token,mknode("INDEX",yystack.l_mark[-1],NULL,NULL,NULL),NULL,NULL,NULL);
							yyval->isArray = 1;
							char tempFreshVar1[10], tempFreshVar2[10];
							strcpy(tempFreshVar1, freshVar());
							strcat(yyval->code, yystack.l_mark[-1]->code);
							strcat(yyval->code,"\t");
							strcat(yyval->code, tempFreshVar1);
							strcat(yyval->code, ":=");
							strcat(yyval->code, yystack.l_mark[-1]->var);
							strcat(yyval->code, "\t\n\t");
							strcpy(tempFreshVar2, freshVar());
							strcat(yyval->code, tempFreshVar2);
							strcat(yyval->code, ":=4*");
							strcat(yyval->code, tempFreshVar1);
							strcat(yyval->code, "\n\t");
							strcpy(tempFreshVar1, freshVar());
							strcat(yyval->code, tempFreshVar1);
							strcat(yyval->code, ":=");
							strcat(yyval->code, yystack.l_mark[-3]->token);
							strcat(yyval->code, "+");
							strcat(yyval->code, tempFreshVar2);
							strcat(yyval->code, "\n");
							strcat(yyval->var,"*(");
							strcat(yyval->var, tempFreshVar1);
							strcat(yyval->var,")");
						
						}
break;
case 44:
#line 313 "proj.y"
	{ 
															yyval=mknode(yystack.l_mark[-3]->token,yystack.l_mark[-1],NULL,NULL,NULL);
															char tempPushParams[33];
															strcat(yyval->code, yystack.l_mark[-1]->code);
															strcat(yyval->code, yystack.l_mark[-3]->code);
															strcpy(yyval->var,freshVar());
															itoa(countPushParams(yyval->code),tempPushParams, 10);
															basicOperationCode(&(yyval->code),"",yystack.l_mark[-3]->code,yyval->var," LCall ",yystack.l_mark[-3]->token,"_");
															strcat(yyval->code, "\tPopParams ");
															strcat(yyval->code, tempPushParams);
															strcat(yyval->code, "\n");
															
															
														}
break;
case 45:
#line 327 "proj.y"
	{ 			yyval=mknode(yystack.l_mark[-2]->token,mknode("VARIABLES",NULL,NULL,NULL,NULL),NULL,NULL,NULL); 
															strcat(yyval->code, yystack.l_mark[-2]->code);
															strcpy(yyval->var,freshVar());
															basicOperationCode(&(yyval->code),"",yystack.l_mark[-2]->code,yyval->var," LCall ",yystack.l_mark[-2]->token,"_");
															

						}
break;
case 46:
#line 336 "proj.y"
	{
						
						yyval=mknode("IF",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\tIfz ");
						strcat(yyval->code,yystack.l_mark[-2]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[0]->code);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":");
						}
break;
case 47:
#line 353 "proj.y"
	{
						yyval=mknode("IF",yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0],NULL);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						strcat(yyval->code,yystack.l_mark[-4]->code);
						strcat(yyval->code,"\tIfz ");
						strcat(yyval->code,yystack.l_mark[-4]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,"goto ");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":\t\n");
						strcat(yyval->code, yystack.l_mark[0]->code);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,":\t");
						
						}
break;
case 48:
#line 376 "proj.y"
	{
							yyval=mknode("IF",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
							yyval->begin = freshLabel();
							yyval->next = freshLabel();
							strcat(yyval->code,yystack.l_mark[-2]->code);
							strcat(yyval->code,"\tIfz ");
							strcat(yyval->code,yystack.l_mark[-2]->var);
							strcat(yyval->code," goto ");
							strcat(yyval->code,yyval->begin);
							strcat(yyval->code,"\n");
							strcat(yyval->code,yystack.l_mark[0]->code);
							strcat(yyval->code,"\n\t");
							strcat(yyval->code,yyval->begin);
							strcat(yyval->code,":");
						}
break;
case 49:
#line 391 "proj.y"
	{ 
						
						yyval=mknode("IF",yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0],NULL);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						strcat(yyval->code,yystack.l_mark[-4]->code);
						strcat(yyval->code,"\tIfz ");
						strcat(yyval->code,yystack.l_mark[-4]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,"goto ");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":\t\n");
						strcat(yyval->code, yystack.l_mark[0]->code);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,":\t");
						}
break;
case 50:
#line 416 "proj.y"
	{ 
						
						yyval=mknode("WHILE",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						strcat(yyval->code,"\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":\n");
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\tifz ");
						strcat(yyval->code,yystack.l_mark[-2]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[0]->code);
						strcat(yyval->code,"\n\tgoto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,":\t");												
						}
break;
case 51:
#line 437 "proj.y"
	{ 
						
						yyval=mknode("FOR",yystack.l_mark[-5],yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0]);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						strcat(yyval->code,yystack.l_mark[-5]->code);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":\n");
						strcat(yyval->code,yystack.l_mark[-4]->code);
						strcat(yyval->code,"\tifz ");
						strcat(yyval->code,yystack.l_mark[-4]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[0]->code);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\n\tgoto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,":\t");	
						
						}
break;
case 52:
#line 462 "proj.y"
	{ 
						
						yyval=mknode("WHILE",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						strcat(yyval->code,"\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":\n");
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\tifz ");
						strcat(yyval->code,yystack.l_mark[-2]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[0]->code);
						strcat(yyval->code,"\n\tgoto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,":\t");
						}
break;
case 53:
#line 483 "proj.y"
	{ 
						
						yyval=mknode("FOR",yystack.l_mark[-5],yystack.l_mark[-4],yystack.l_mark[-2],yystack.l_mark[0]);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						strcat(yyval->code,yystack.l_mark[-5]->code);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":\n");
						strcat(yyval->code,yystack.l_mark[-4]->code);
						strcat(yyval->code,"\tifz ");
						strcat(yyval->code,yystack.l_mark[-4]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[0]->code);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\n\tgoto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,":\t");	

						}
break;
case 54:
#line 509 "proj.y"
	{
						
						yyval=mknode("DO WHILE",yystack.l_mark[-2],yystack.l_mark[-5], NULL, NULL);
						yyval->begin = freshLabel();
						yyval->next = freshLabel();
						strcat(yyval->code,"\t");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,":\n");
						strcat(yyval->code,yystack.l_mark[-5]->code);
						strcat(yyval->code,"\n");
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code,"\tifz ");
						strcat(yyval->code,yystack.l_mark[-2]->var);
						strcat(yyval->code," goto ");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,"goto ");
						strcat(yyval->code,yyval->begin);
						strcat(yyval->code,"\n\t");
						strcat(yyval->code,yyval->next);
						strcat(yyval->code,":\t");
						
						}
break;
case 55:
#line 534 "proj.y"
	{ 
							yyval=mknode(yystack.l_mark[-1]->token,yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
							strcat(yyval->code,yystack.l_mark[0]->code);
							strcat(yyval->code,"\t");
							strcat(yyval->code,yystack.l_mark[-2]->token);
							strcat(yyval->code,":=");
							strcat(yyval->code,yystack.l_mark[0]->var);
						}
break;
case 56:
#line 545 "proj.y"
	{ yyval=mknode("RETURN",yystack.l_mark[-1],NULL,NULL,NULL); 
											strcat(yyval->code, "\n");
											strcat(yyval->code, yystack.l_mark[-1]->code);
											strcat(yyval->code, "\tRETURN ");
											strcat(yyval->code, yystack.l_mark[-1]->var);
						}
break;
case 57:
#line 551 "proj.y"
	{ yyval=mknode("RETURN",NULL,NULL,NULL,NULL);
						
										 strcat(yyval->code, "");
						}
break;
case 59:
#line 559 "proj.y"
	{ 
						
						yyval=mknode("VARIABLES",yystack.l_mark[0],yystack.l_mark[-2],NULL,NULL); 
						strcat(yyval->code,yystack.l_mark[-2]->code);
						strcat(yyval->code, "\tPushParams ");
						strcat(yyval->code, yystack.l_mark[-2]->var);
						strcat(yyval->code, "\n");
						strcat(yyval->code, yystack.l_mark[0]->code);


						}
break;
case 60:
#line 570 "proj.y"
	{yyval=mknode("VARIABLES",yystack.l_mark[0],NULL,NULL,NULL);

							strcat(yyval->code,yystack.l_mark[0]->code);
							strcat(yyval->code, "\tPushParams ");
							strcat(yyval->code, yystack.l_mark[0]->var);
							strcat(yyval->code, "\n");
						}
break;
case 61:
#line 580 "proj.y"
	{
														yyval=mknode("+",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"+");
													}
break;
case 62:
#line 585 "proj.y"
	{
														yyval=mknode("-",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"-");
													}
break;
case 63:
#line 590 "proj.y"
	{
														yyval=mknode("*",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"*");
													}
break;
case 64:
#line 595 "proj.y"
	{
														yyval=mknode("/",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"/");
													}
break;
case 65:
#line 600 "proj.y"
	{
														yyval=mknode("&&",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"&&");	
													}
break;
case 66:
#line 605 "proj.y"
	{
														yyval=mknode("||",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"||");	
													}
break;
case 67:
#line 610 "proj.y"
	{
														yyval=mknode("==",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"==");	
													}
break;
case 68:
#line 615 "proj.y"
	{
														yyval=mknode("!=",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"!=");	
													}
break;
case 69:
#line 620 "proj.y"
	{
														yyval=mknode(">",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,">");

													}
break;
case 70:
#line 626 "proj.y"
	{
														char *tmp = (char*)malloc(sizeof(char)*5000);
														char *temp1 =  (char*)malloc(sizeof(char)*100);
														char *temp2 =  (char*)malloc(sizeof(char)*100);
														char *temp3 =  (char*)malloc(sizeof(char)*100);
														yyval=mknode(">=",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(temp1, freshVar());
														strcpy(yyval->var,temp1);
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,">");
														strcpy(temp2,freshVar());
														strcpy(yyval->var,temp2);
														basicOperationCode(&tmp,yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"==");
														strcpy(temp3, freshVar());
														strcpy(yyval->var,temp3);
														basicOperationCode(&tmp,yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,temp1,temp2,"||");
														strcat(yyval->code,tmp);
													}
break;
case 71:
#line 643 "proj.y"
	{
														yyval=mknode("<",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"<");
													}
break;
case 72:
#line 648 "proj.y"
	{
														char *tmp = (char*)malloc(sizeof(char)*5000);
														char *temp1 =  (char*)malloc(sizeof(char)*100);
														char *temp2 =  (char*)malloc(sizeof(char)*100);
														char *temp3 =  (char*)malloc(sizeof(char)*100);
														yyval=mknode("<=",yystack.l_mark[-2],yystack.l_mark[0],NULL,NULL);
														strcpy(temp1, freshVar());
														strcpy(yyval->var,temp1);
														basicOperationCode(&(yyval->code),yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"<");
														strcpy(temp2,freshVar());
														strcpy(yyval->var,temp2);
														basicOperationCode(&tmp,yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,yystack.l_mark[-2]->var,yystack.l_mark[0]->var,"==");
														strcpy(temp3, freshVar());
														strcpy(yyval->var,temp3);
														basicOperationCode(&tmp,yystack.l_mark[-2]->code,yystack.l_mark[0]->code,yyval->var,temp1,temp2,"||");
														strcat(yyval->code,tmp);
													}
break;
case 73:
#line 665 "proj.y"
	{
														yyval=mknode("!",yystack.l_mark[0],NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),"",yystack.l_mark[0]->code,yyval->var,"!","",yystack.l_mark[0]->var);
													}
break;
case 74:
#line 670 "proj.y"
	{
														yyval=mknode("^",yystack.l_mark[0],NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),"",yystack.l_mark[0]->code,yyval->var,"*","",yystack.l_mark[0]->var);
													}
break;
case 75:
#line 675 "proj.y"
	{
														yyval=mknode("&",yystack.l_mark[0],NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),"",yystack.l_mark[0]->code,yyval->var,"&","",yystack.l_mark[0]->var);
													}
break;
case 76:
#line 680 "proj.y"
	{
														yyval=yystack.l_mark[0];
														yyval->var=yystack.l_mark[0]->token;
														yyval->code=(char*)malloc(sizeof(char)+1);
													}
break;
case 77:
#line 685 "proj.y"
	{
														yyval=mknode("true",NULL,NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),"","",yyval->var,"true","","");
													}
break;
case 78:
#line 690 "proj.y"
	{
														yyval=mknode("false",NULL,NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),"","",yyval->var,"false","","");	
													}
break;
case 79:
#line 695 "proj.y"
	{
														yyval=yystack.l_mark[0];
														yyval->var=yystack.l_mark[0]->token;
													}
break;
case 80:
#line 699 "proj.y"
	{yyval=yystack.l_mark[-1];}
break;
case 81:
#line 700 "proj.y"
	{
														yyval=mknode("ABS",yystack.l_mark[-1],NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),"",yystack.l_mark[-1]->code,yyval->var,"|","|",yystack.l_mark[-1]->var);
													}
break;
case 82:
#line 705 "proj.y"
	{
														yyval=mknode("NULL",NULL,NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),"","",yyval->var,"NULL","","");
													}
break;
case 83:
#line 710 "proj.y"
	{
														yyval=mknode("FUNC CALL",yystack.l_mark[0],NULL,NULL,NULL);
														
														strcpy(yyval->code, yystack.l_mark[0]->code);
														strcpy(yyval->var,yystack.l_mark[0]->var);
														
													}
break;
case 84:
#line 717 "proj.y"
	{
														yyval=mknode("CHAR VAR",yystack.l_mark[0],NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[0]->code,"",yyval->var,yystack.l_mark[0]->var,"","");
													}
break;
case 85:
#line 722 "proj.y"
	{
														yyval=mknode("STRING VAR",yystack.l_mark[0],NULL,NULL,NULL);
														strcpy(yyval->var,freshVar());
														basicOperationCode(&(yyval->code),yystack.l_mark[0]->code,"",yyval->var,yystack.l_mark[0]->var,"","");
													}
break;
case 86:
#line 729 "proj.y"
	{
									yyval=mknode(yytext,NULL,NULL,NULL,NULL);
								}
break;
case 87:
#line 732 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 88:
#line 733 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 89:
#line 734 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 90:
#line 737 "proj.y"
	{
							yyval=mknode(yytext,NULL,NULL,NULL,NULL);
							strcpy(yyval->var, yytext);
						}
break;
case 91:
#line 743 "proj.y"
	{yyval=mknode("=",NULL,NULL,NULL,NULL);}
break;
case 92:
#line 746 "proj.y"
	{
						yytext[2] = '\0';
						yyval=mknode(&yytext[1],NULL,NULL,NULL,NULL);
						yytext[2] = '\'';
						yyval->var=yytext;
						yyval->code=(char*)malloc(sizeof(char)+1);
						}
break;
case 93:
#line 755 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 94:
#line 758 "proj.y"
	{yyval=mknode(yytext,NULL,NULL,NULL,NULL);}
break;
case 95:
#line 761 "proj.y"
	{
						int i;char c;
						char *tmp;
						tmp=(char*)malloc(sizeof(char)*100);
						strcpy(tmp,yytext);
						/*Remove last " from the string variable*/
						for(i=1;yytext[i]!='\0';i++){
							c=yytext[i];
							if(yytext[i]=='"')
								yytext[i]='\0';
							}
						yyval=mknode(&yytext[1],NULL,NULL,NULL,NULL);
						yyval->code=(char*)malloc(sizeof(char)+1);
						yyval->var=tmp;
						}
break;
#line 1803 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
