/*	Aviv Adar 208897371
	Amit Twati 318278181
	Yarden Cherry 
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE struct node*

typedef struct node{
	char *token;
	struct node *left;
	struct node *mid1;
	struct node *mid2;
	struct node *right;
	
} node;

extern int yylex();
extern int yylineno;
extern char *yytext;

node* mknode(char* token,node* left,node* mid1,node* mid2, node* right);
void Printtree(node* tree,int tab);
int isTerminal(node* tree);
int AllChildTerminal(node* tree);
int yyerror(const char *msg);


%}

%token BOOL VOID CHAR INT STRING INTP CHARP;
%token IF ELSE WHILE DO FOR RRETURN NNULL;

%token AND DIVIDE ASSIGN ISEQUAL GREATER GREATEREQ LESS LESSEQ MINUS NOT NOTEQUAL OR PLUS MULT BAND BXOR;

%token MAIN BOOL_TRUE BOOL_FALSE;

%token DPRIME CHAR;

%token NUM ID OCT HEX BIN;

%token SEMI COMMA ABS OBRACE CBRACE OBRACKET CBRACKET OSQRERACKET CSQRERACKET;

%token OCMNT CCMNT SINMGLE_COMMENT;
%token CCMNT;

%left PLUS MINUS AND OR ISEQUAL NOTEQUAL GREATER GREATEREQ LESS LESSEQ
%left MULT DIVIDE
%right ASSIGN NOT BXOR

%%

START:					PROGRAM {Printtree($1,0);}
						;
						
//START:					PROGRAM {pre($1,0);printf("\n");in($1,0);printf("\n");Printtree($1,0);}
//						;						
/* 
The program can contain many functions above the main function
*/
PROGRAM:				FUNCTIONS MAIN_FUNCTION {
						
						$$=mknode("PROGRAM",$1,$2 ,NULL,NULL);
						
						}
						| MAIN_FUNCTION	{
						
						$$=mknode("PROGRAM",$1,NULL ,NULL,NULL);
						
						}
						;	
						
						
/*
Every legal program should have one and only one function: void main()
*/
MAIN_FUNCTION:			VOID MAIN OBRACKET CBRACKET OBRACE BODY CBRACE {
						
						$$=mknode("MAIN",$6,NULL,NULL,NULL);
						
						}
						;

FUNCTIONS:				FUNCTIONS FUNCTION{
						
						$$=mknode("FUNC_NODE",$1,$2,NULL,NULL);
						
						}
						| FUNCTION
						
						;

/*
FUNC_TYPE can be boolean , char , int , charp , intp or void.
The body can contain variable declarations, statements and return statment in this order only. */					
FUNCTION:				TYPE id OBRACKET F_PARAMS CBRACKET OBRACE BODY CBRACE {
						
						$$=mknode("FUNCTION",$1,$2,$4,$7);
											
						}
						|
						VOID id OBRACKET F_PARAMS CBRACKET OBRACE BODY CBRACE {
						
						$$=mknode("FUNCTION",$1,$2,$4,$7);
											
						}
						;
						
BODY:					VAR_DECLERACTIONS FUNCTIONS STATMENTS RETURN_STATMENT {
						
						$$=mknode("BODY",$2,$3,$4,NULL);
						
						}
						|
						VAR_DECLERACTIONS STATMENTS RETURN_STATMENT {
						
						$$=mknode("BODY",$2,$3,NULL,NULL);
						
						}
						;
						
						
/*
Function Parameters (can be empty)
*/					
F_PARAMS:				F_PARAMSS
						|
						;

F_PARAMSS:				F_PARAMSS COMMA PARAM
						| PARAM
						;

/*
The types of the parameters can be boolean , char , int , charp , intp or string
*/
PARAM:					PARAM_TYPE id
						;
						

VAR_DECLERACTIONS:		VAR_DECLERACTIONS VAR_DECLERACTION
						|
						;


VAR_DECLERACTION:		TYPE IDS SEMI
						| STRING SID SEMI
						;

IDS:					IDS COMMA id
						| id
						;
						
SID:					SID COMMA ID OSQRERACKET NUM CSQRERACKET 
						| ID OSQRERACKET NUM CSQRERACKET
						;
						
PARAM_TYPE:				TYPE
						| STRING
						;
						
TYPE:					BOOL
						| CHAR
						| INT
						| INTP
						| CHARP 
						;
						
						
STATMENTS:				STATMENT STATMENTS{
						$$=mknode("STATMENT_NODE",$1,$2,NULL,NULL);
						}
						|
						;
						
STATMENT:				ASSIGNMENT{$$=$1;}		
						| FUNC_CALL	{$$=$1;}	
						| IFS {$$=$1;}
						| LOOPS {$$=$1;}
						;
						

ASSIGNMENT:				id assign EXPR SEMI{
						
						$$=mknode($2->token,$1,$3,NULL,NULL);
						
						}
						| id assign char SEMI {
							$$=mknode($2->token,$1,$3,NULL,NULL);
						}
						| id assign DPRIME id DPRIME SEMI {
							$$=mknode($2->token,$1,$4,NULL,NULL);
						}
						;
						
						
FUNC_CALL:				id assign id OBRACKET EXPR_LIST CBRACKET SEMI { $$=mknode($2->token,$1,$3,$5,NULL); }
						| id assign id OBRACKET CBRACKET SEMI { $$=mknode($2->token,$1,$3,mknode("VARIABLES",NULL,NULL,NULL,NULL),NULL); }
						| id OBRACKET EXPR_LIST CBRACKET SEMI { $$=mknode($1->token,$3,NULL,NULL,NULL); }
						| id OBRACKET CBRACKET SEMI { $$=mknode($1->token,mknode("VARIABLES",NULL,NULL,NULL,NULL),NULL,NULL,NULL); }
						;					
						
IFS:					IF OBRACKET EXPR CBRACKET OBRACE NESTED_STATMENTS CBRACE{
						
						$$=mknode("IF",$3,$6,NULL,NULL);
						
						}
						| IF OBRACKET EXPR CBRACKET OBRACE NESTED_STATMENTS CBRACE ELSE OBRACE NESTED_STATMENTS CBRACE{
					
						$$=mknode("IF",$3,$6,$10,NULL);
						
						}
						| IF OBRACKET EXPR CBRACKET STATMENT{
						
						$$=mknode("IF",$3,$5,NULL,NULL);
						
						}
						| IF OBRACKET EXPR CBRACKET OBRACE NESTED_STATMENTS CBRACE ELSE STATMENT { 
						
						$$=mknode("IF",$3,$6,$9,NULL);
						
						}
						;
						
LOOPS:					WHILE OBRACKET EXPR CBRACKET OBRACE NESTED_STATMENTS CBRACE{ 
						
						$$=mknode("WHILE",$3,$6,NULL,NULL);
						
						}
						| FOR OBRACKET ASSIGNMENT EXPR SEMI UPDATES CBRACKET OBRACE NESTED_STATMENTS CBRACE{ 
						
						$$=mknode("FOR",$3,$4,$6,$9);
						
						}
						| WHILE OBRACKET EXPR CBRACKET STATMENT{ 
						
						$$=mknode("WHILE",$3,$5,NULL,NULL);
						
						}
						| FOR OBRACKET ASSIGNMENT EXPR SEMI UPDATES CBRACKET STATMENT{ 
						
						$$=mknode("FOR",$3,$4,$6,$8);
						
						}
						
						| DO OBRACE NESTED_STATMENTS CBRACE WHILE OBRACKET EXPR CBRACKET SEMI{
						
						$$=mknode("DO WHILE",$7,$3, NULL, NULL);
						
						}
					
						;
						
NESTED_STATMENTS:		STATMENTS { $$=mknode("BODY",$1,NULL,NULL,NULL); }
						;
						
UPDATES:				id plus plus{ $$=mknode("=",$1,mknode($2->token,$1,mknode("1",NULL,NULL,NULL,NULL),NULL,NULL),NULL,NULL); }
						| plus plus id { $$=mknode("=",$3,mknode($2->token,$3,mknode("1",NULL,NULL,NULL,NULL),NULL,NULL),NULL,NULL); }
						| id minus minus { $$=mknode("=",$1,mknode($2->token,$1,mknode("1",NULL,NULL,NULL,NULL),NULL,NULL),NULL,NULL); }
						| minus minus id { $$=mknode("=",$3,mknode($2->token,$3,mknode("1",NULL,NULL,NULL,NULL),NULL,NULL),NULL,NULL); }
						| id assign EXPR { $$=mknode($2->token,$1,$3,NULL,NULL);}
						;
						
				
RETURN_STATMENT:		RRETURN EXPR SEMI { $$=mknode("RETURN",$2,NULL,NULL,NULL); }
						| RRETURN SEMI { $$=mknode("RETURN",NULL,NULL,NULL,NULL); }
						|
						;

EXPR_LIST:				EXPR_LIST COMMA EXPR { 
						$$=mknode("VARIABLES",$1,$3,NULL,NULL); 
						}
						| EXPR{$$=mknode("VARIABLES",$1,NULL,NULL,NULL); }
						;						
	
						
EXPR:					EXPR PLUS EXPR				{$$=mknode("+",$1,$3,NULL,NULL);}
						| EXPR MINUS EXPR			{$$=mknode("-",$1,$3,NULL,NULL);}
						| EXPR MULT EXPR			{$$=mknode("*",$1,$3,NULL,NULL);}
						| EXPR DIVIDE EXPR			{$$=mknode("/",$1,$3,NULL,NULL);}
						| EXPR AND EXPR				{$$=mknode("&&",$1,$3,NULL,NULL);}
						| EXPR OR EXPR				{$$=mknode("||",$1,$3,NULL,NULL);}
						| EXPR ISEQUAL EXPR			{$$=mknode("==",$1,$3,NULL,NULL);}
						| EXPR NOTEQUAL EXPR		{$$=mknode("!=",$1,$3,NULL,NULL);}
						| EXPR GREATER EXPR			{$$=mknode(">",$1,$3,NULL,NULL);}
						| EXPR GREATEREQ EXPR		{$$=mknode(">=",$1,$3,NULL,NULL);}
						| EXPR LESS EXPR			{$$=mknode("<",$1,$3,NULL,NULL);}
						| EXPR LESSEQ EXPR			{$$=mknode("<=",$1,$3,NULL,NULL);}
						| NOT EXPR					{$$=mknode("!",$2,NULL,NULL,NULL);}
						| BXOR EXPR					{$$=mknode("^",$2,NULL,NULL,NULL);}
						| NUMS						{$$=$1;}
						| BOOL_TRUE					{$$=mknode("true",NULL,NULL,NULL,NULL);}
						| BOOL_FALSE				{$$=mknode("false",NULL,NULL,NULL,NULL);}
						| id						{$$=$1;}
						| OBRACKET EXPR CBRACKET	{$$=$2;}
						| ABS EXPR ABS 				{$$=mknode("ABS",$2,NULL,NULL,NULL);}
						;	
						
NUMS:					NUM		{$$=mknode(yytext,NULL,NULL,NULL,NULL);}	
						| OCT	{$$=mknode(yytext,NULL,NULL,NULL,NULL);}
						| HEX	{$$=mknode(yytext,NULL,NULL,NULL,NULL);}
						| BIN	{$$=mknode(yytext,NULL,NULL,NULL,NULL);}
						;
						
id:						ID 	{$$=mknode(yytext,NULL,NULL,NULL,NULL);}
						;

assign:					ASSIGN {$$=mknode("=",NULL,NULL,NULL,NULL);}
						;

plus:					PLUS {$$=mknode("+",NULL,NULL,NULL,NULL);}
						;
						
minus:					MINUS {$$=mknode("-",NULL,NULL,NULL,NULL);}
						;
						
char:					CHAR {
						yytext[2] = '\0';
						$$=mknode(&yytext[1],NULL,NULL,NULL,NULL);}
						;

%%

#include "lex.yy.c"

int main(){
    return yyparse();
}

node* mknode(char* token,node* left,node* mid1,node* mid2, node* right){
	node *newnode = (node*)malloc(sizeof(node));
   	char *newstr = (char*)malloc(sizeof(token)+1);
   	strcpy (newstr, token);
    newnode->token = newstr;
	newnode->left=left;
	newnode->mid1=mid1;
	newnode->mid2=mid2;
	newnode->right=right;
}

int isTerminal(node* tree){
	
	if(tree){
		return (tree->left == NULL) && (tree->mid1 == NULL) && (tree->mid2 == NULL) && (tree->right == NULL);
	}
	return 1;
}

int AllChildTerminal(node* tree){
	if(tree->left){
		if(isTerminal(tree->left)){
			if(tree->mid1){
				if(isTerminal(tree->mid1)){
					if(tree->mid2){
						if(isTerminal(tree->mid2)){
							if(tree->right){
								return isTerminal(tree->right);
							}else{
								return 1;
							}
						}else{
							return 0;
						}
					}else{
						return 1;
					}
				}else{
					return 0;
				}
			}else{
				return 1;
			}
		}else{
			return 0;
		}
	}else{
		return 1;
	}
}
			

void Printtree(node* tree,int tab){
	
	if(isTerminal(tree)){
		printf(" %s",tree->token);
		return;
	}
	
	if(strcmp("FUNC_NODE",tree->token) && strcmp("STATMENT_NODE",tree->token)){
		for(int i=0;i<tab;i++)
			printf("    ");
		printf("(%s",tree->token);
		
	}
	else{
		tab--;
	}
	
	if(tree->left){
		if(!isTerminal(tree->left) )
			printf("\n");
		//printf("%s\t", tree->token);
		Printtree(tree->left,tab+1);	
	}
				
	if(tree->mid1){
		if(!isTerminal(tree->mid1))
			printf("\n");	
		Printtree(tree->mid1,tab+1);

	}
				
	if(tree->mid2 ){
		if(!isTerminal(tree->mid2))
			printf("\n");
		Printtree(tree->mid2,tab+1);

	}
				
	if(tree->right){
		if(!isTerminal(tree->right))
			printf("\n");
		Printtree(tree->right,tab+1);
	}
	
	if(strcmp("FUNC_NODE",tree->token) && strcmp("STATMENT_NODE",tree->token) || AllChildTerminal(tree)){
		if(!isTerminal(tree->left) || !isTerminal(tree->mid1) || !isTerminal(tree->mid2) || !isTerminal(tree->right)){
			printf("\n");
			for(int i=0;i<tab;i++)
				printf("    ");
			printf(")");
		}else{
			printf(")\n");
			for(int i=0;i<tab;i++)
				printf("    ");
		}	
	}
	
}

int yyerror(const char *msg)
{
	fflush(stdout);
	fprintf(stderr, "Error: %s at line %d\n", msg,yylineno);
	fprintf(stderr, "Parser does not expect '%s'\n",yytext);
}


