%option noyywrap

%{
#include "SymbolNodes.h"
#include "Grammar.tab.h"
#include "SymbolTable.h"
#include "ReservationTable.h"
#include <stdio.h>
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
typedef yy::parser::token token;
%}

%%

"if" {return token::IF;}
"else" {return token::ELSE;}
"for" {return token::FOR;}
"while" {return token::WHILE;}
"do" {return token::DO;}
"printf" {return token::PRINTF;}
\" {return '"';}


"{"		{return '{';}
"}"		{return '}';}

"("		{return '(';}
")"		{return ')';}

"+"		{return '+';} 
"-"		{return '-';}

"++"	{return token::INC;} 
"--"	{return token::DCR;} 

":"		{return ':';} 
"?"		{return '?';}

"!"		{return '!';} 
"~"		{return '~';} 

"*"		{return '*';} 
"/"		{return '/';} 
"%"		{return '%';} 



"<"		{return '<';}
">"		{return '>';}
">="	{return token::BIGGER_EQUAL;}
"<="	{return token::SMALLER_EQUAL;}

"=="	{return token::EQ;}
"!="	{return token::NOT_EQ;}

"&"		{return '&';} 
"^"		{return '^';} 
"|"		{return '|';} 

"&&"	{return token::LOG_AND;}
"||"	{return token::LOG_OR;}

"="		{return '=';}

"0"|[-]?[1-9][0-9]* { yylval->node = new CNUMBER(yytext);
					return token::NUMBER;}
\".*\n*\" { yylval->node = new CSTRING(yytext);
		return token::STRING;}


[a-zA-Z][0-9a-zA-Z_]* { yylval->node = g_symbolTable.GetIdentifier(yytext);
					return token::IDENTIFIER;}

"\;" {return ';';}
[ \n\r\t]+ ;

%%