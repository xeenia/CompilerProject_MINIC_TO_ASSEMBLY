#include "SymbolTable.h"

SymbolTable g_symbolTable;

STNode* SymbolTable::GetIdentifier(char* name){
	map<string, STNode *>::iterator it;
	STNode* node = 0;

	it = m_symbolTable.find(name);
	if (it != m_symbolTable.end()) {
		node = m_symbolTable[name];
	}
	else
	{
		node = new CIDENTIFIER(name);
		m_symbolTable[name] =node;
	}
	return node;
}

