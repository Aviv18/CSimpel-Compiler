%{

extern int yylineno;

%}

%%

"//".*                  { /* comments */ }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] { /* comments */ }

"boolean"				return BOOL;
"char"					return CHAR;
"void"					return VOID;
"int"					return INT;
"string" 				return STRING;
"intp"					return INTP;
"charp"					return CHARP;
"if" 					return IF;
"else"					return ELSE;
"while"					return WHILE;
"do"					return DO;
"for"					return FOR;
"return" 				return RRETURN;
"null" 					return NNULL;


"&&" 					return AND;
"/" 					return DIVIDE;
"=" 					return ASSIGN;
"==" 					return ISEQUAL;
">" 					return GREATER;
">=" 					return GREATEREQ;
"<" 					return LESS;
"<=" 					return LESSEQ;
"-" 					return MINUS;
"!" 					return NOT;
"!=" 					return NOTEQUAL;
"||" 					return OR;
"+" 					return PLUS;
"*" 					return MULT;
"&" 					return BAND;
"^" 					return BXOR;

"main"					return MAIN;
"true"					return BOOL_TRUE;
"false"					return BOOL_FALSE;

"\""					return DPRIME;
"'"[A-Za-z]"'" 				return CHAR;

0|[1-9][0-9]* 			return NUM;
[A-Za-z][A-Za-z0-9]* 	return ID;

0[1-7][0-7]* 			return OCT;
0[x|X][0-9A-F]+ 		return HEX;
[0-1]+b 				return BIN;

";"						return SEMI;
","						return COMMA;
"|"						return ABS;
"{" 					return OBRACE;
"}" 					return CBRACE;
"(" 					return OBRACKET;
")" 					return CBRACKET;
"["						return OSQRERACKET;
"]"						return CSQRERACKET;




[ \t\f\v]				;
[\n]					{ yylineno = yylineno + 1; }

. 						return yytext[0];

%%



