#include <stdio.h>
#include <stdlib.h>
#include "Grammar.tab.h"
#include "STNode.h"
#include "SymbolTable.h"
extern FILE* yyin;
FILE* lol;
ofstream* asl;
int main(int argc, char** argv)
{

	fopen_s(&yyin, "CProgram.txt", "r");
	yy::parser* p = new yy::parser();
	p->parse();

	ofstream* f = new ofstream("stree.dot", ofstream::out);
	asl = new ofstream("AssemblyProgram.txt");
	g_root->Visit_SyntaxTreePrinter(f, nullptr);
	system("dot -Tgif stree.dot -o stree.dot.gif");
	g_root->Visit_Eval();
	//g_root->Get_FileP(asl);
	(*asl) << "INCLUDE Irvine32.inc\n";
	(*asl) << ".data\n\n";
	map<string, STNode*>::iterator it = g_symbolTable.m_symbolTable.begin();
	
	for (it; it != g_symbolTable.m_symbolTable.end(); it++){
		CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(it->second);
		(*asl) << id->m_name<< " DWORD ?"  << endl;
	}
	(*asl) << "\n.code\nmain PROC\n";
	g_root->Visit_GenAssembly(asl,NT_COMPILEUNIT, "0");
	(*asl) << "main ENDP\nend main\n";
	return 0;
}