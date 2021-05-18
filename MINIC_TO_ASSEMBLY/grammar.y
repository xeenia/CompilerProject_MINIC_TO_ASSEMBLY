%language "C++"


%{
#include <stdio.h>
#include "SymbolNodes.h"
#include "Grammar.tab.h"
#include "SymbolTable.h"
#include "ReservationTable.h"

extern FILE *lol;
extern ofstream* asl;
extern int yylex(yy::parser::semantic_type *yylvall);
%}
%code requires{
#include "STNode.h"
}
%union{
	STNode* node;
}
%start compileUnit //orismos arikou sumvolou
%token <node> NUMBER IDENTIFIER
%token IF ELSE WHILE FOR DO PRINTF STRING
%left '?' ':'
%left LOG_OR
%left LOG_AND
%left '|'
%left '^'
%left '&'
%left EQ NOT_EQ
%left '<' '>' BIGGER_EQUAL SMALLER_EQUAL
%left '+' '-'
%left '*' '/' '%'
%right '!' '~'
%right INC DCR
%left '"'
%left '(' ')'
%type <node> expression compileUnit statements statement while_expression compound_exp inside_list kind_of_if if_statement for_expression do_while_expression 
%type <node> printf_statement
%%


compileUnit : statements { g_root = $$ = new CCompileUnit(); $$->AddChild($1);} 
		;

statements :  statement { $$ = new CStatements(); $$->AddChild($1);}
		| statements statement { $$ = new CStatements(); $$->AddChild($1); $$->AddChild($2);}
		;

statement : expression ';'  { $$ = new CStatement(); $$->AddChild($1);}
		| ';' { $$ = new CStatement();}
		| compound_exp
		| while_expression
		| for_expression
		| do_while_expression
		| kind_of_if
		| if_statement
		| printf_statement
		;


compound_exp : '{' '}'  {$$ = new CCompound();}
			 | '{' inside_list '}' {$$ = new CCompound(); $$->AddChild($2);}
			 ;


inside_list : statement { $$= new CInsideList(); $$->AddChild($1);}
		    | inside_list statement  { $$= new CInsideList(); $$->AddChild($1);  $$->AddChild($2);}
		    ;

while_expression : WHILE '(' expression ')' statement {$$ = new CWhile(); $$->AddChild($3); $$->AddChild($5);}
                 ;

for_expression : FOR '(' expression ';' expression ';' expression ')' statement { $$ = new CFor(); $$->AddChild($3); $$->AddChild($5); $$->AddChild($7); $$->AddChild($9);}
			   ;

do_while_expression : DO statement  WHILE '(' expression ')' ';' { $$ = new CDo_While(); $$->AddChild($2); $$->AddChild($5);}
					;

kind_of_if : '(' expression ')' '?' expression ':' expression { $$= new CIf_telesths(); $$->AddChild($2); $$->AddChild($5); $$->AddChild($7);}
		   | IDENTIFIER '=' '(' expression ')' '?' expression ':' expression { $$= new CIf_telesths(); $$->AddChild($1); $$->AddChild($4); $$->AddChild($7); $$->AddChild($9);}
		   ;

if_statement : IF '(' expression ')' statement ELSE statement  { $$ = new CIf_statement(); $$->AddChild($3); $$->AddChild($5); $$->AddChild($7);}
			 | IF '(' expression ')' statement { $$ = new CIf_statement(); $$->AddChild($3); $$->AddChild($5);} 
			 ;

printf_statement : PRINTF '(' STRING  ')' ';' { $$ = new CPrintf('y');}
			     ;


expression  : NUMBER	
		    | IDENTIFIER 
			| IDENTIFIER '=' expression {$$ = new CAssignment(); $$->AddChild($1); $$->AddChild($3);}
			| expression '+' expression {$$ = new CAddition(); $$->AddChild($1); $$->AddChild($3); } 
			| expression '-' expression {$$ = new CSubtraction(); $$->AddChild($1); $$->AddChild($3);}
			| expression '*' expression {$$ = new CMultiplication(); $$->AddChild($1); $$->AddChild($3);}
			| expression '/' expression {$$ = new CDivision(); $$->AddChild($1); $$->AddChild($3); }
			| expression '%' expression  {$$ = new CModulo(); $$->AddChild($1); $$->AddChild($3);}
			| expression '>' expression  {$$ = new CBigger(); $$->AddChild($1); $$->AddChild($3);}
			| expression '<' expression  {$$ = new CSmaller(); $$->AddChild($1); $$->AddChild($3);}
			| expression '&' expression  {$$ = new CBit_And(); $$->AddChild($1); $$->AddChild($3);}
			| expression '^' expression {$$ = new CBit_Xor(); $$->AddChild($1); $$->AddChild($3);}
			| expression '|' expression  {$$ = new CBit_Or(); $$->AddChild($1); $$->AddChild($3);}
			| expression BIGGER_EQUAL expression {$$ = new CBigger_Eq(); $$->AddChild($1); $$->AddChild($3);}
			| expression SMALLER_EQUAL expression  {$$ = new CSmaller_Eq(); $$->AddChild($1); $$->AddChild($3);}
			| expression EQ expression {$$ = new CEq(); $$->AddChild($1); $$->AddChild($3);}
			| expression NOT_EQ expression  {$$ = new CNot_Eq(); $$->AddChild($1); $$->AddChild($3);}
			| expression LOG_AND expression {$$ = new CLogical_And(); $$->AddChild($1); $$->AddChild($3);}
			| expression LOG_OR expression  {$$ = new CLogical_Or(); $$->AddChild($1); $$->AddChild($3);}
			| '!' expression  {$$ = new CNot(); $$->AddChild($2);}
			| '~' expression  {$$ = new CBit_Not(); $$->AddChild($2);}		
			| IDENTIFIER INC {$$ = new CInc(0); $$->AddChild($1);}
			| INC IDENTIFIER  {$$ = new CInc(1); $$->AddChild($2);}
			| IDENTIFIER DCR {$$ = new CDcr(0); $$->AddChild($1);}
			| DCR IDENTIFIER  {$$ = new CDcr(1); $$->AddChild($2);}
			;




%% 
namespace yy{
	void parser::error (const location_type& loc, const std::string& msg){
		std::cerr << "error at " <<loc << ":" << msg << std::endl;
	}
}
void yyerror(const char *message)
{

	printf("%s", message);



}

