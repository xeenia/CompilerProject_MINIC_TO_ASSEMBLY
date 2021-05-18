#include "STNode.h"
#include <iostream>
STNode* g_root = nullptr, * r_root=nullptr;
int STNode::m_serialCounter = 0;
int STNode::c_if_st_flag = 1;
int STNode::c_if_tel_flag = 1;
int STNode::c_if_else_st_flag = 1;
int STNode::c_while_flag = 1;
int STNode::c_do_while_flag = 1;
int STNode::c_for_flag = 1;
const char* g_nodeTypeLabels[] = {
	"COMPILEUNIT", "STATEMENTS", "STATEMENT",
	"NUMBER","IDENTIFIER", "ADDITION", "SUBTRACTION",
	"MULTIPLICATION", "DIVISION",
	"MODULO", "NOT", "BIT_NOT",
	"BIGGER", "SMALLER",
	"BIT_AND", "BIT_OR", "BIT_XOR",
	"BIGGER_EQ", "SMALLER_EQ",
	"INC", "DCR",
	"EQ", "NOT_EQ",
	"LOG_AND", "LOG_OR", 
	"ASSIGNMENT", "WHILE", "COMPOUND","INSIDELIST", "IF_TELESTHS", "IF_STATEMENT",
	"FOR","DO_WHILE", "PRINTF", "STRING"

};

STNode::STNode(NodeType type) {
	m_nodeType = type;
	m_serial = m_serialCounter++;
	m_children = new list<STNode*>;
	m_parents = new list<STNode*>;
	m_graphvizLabe1 = _strdup(g_nodeTypeLabels[m_nodeType]);
	m_graphvizLabe1.append("_" + std::to_string(m_serial));
	

}

STNode::~STNode() {
	list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++)
	{
		delete* it;
	}
	delete m_children;
	delete m_parents;

}

void STNode::AddChild(STNode* node)
{
	m_children->push_back(node);
	node->m_parents->push_back(this);
}


STNode* STNode::GetChild(int index)
{
	list<STNode*>::iterator it = m_children->begin();
	advance(it, index);
	return *it;

}

STNode* STNode::GetParent(int index)
{
	list<STNode*>::iterator it = m_parents->begin();
	advance(it, index);
	return *it;

}

void STNode::Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent) {
	list<STNode*>::iterator it;
	(*dotFile) << "\"" << GetParent()->GetGraphvizLabel() << "\"->\"" << GetGraphvizLabel() << "\";\n";

	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->Visit_SyntaxTreePrinter(dotFile, this);
	}
}


void STNode::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it;	
	
	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->Visit_GenAssembly(dotFile,NT_COMPILEUNIT, "0");
		//cout << "why\n";
	}
	
}
int STNode::Visit_Eval() {
	list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->Visit_Eval();
		//cout << "                     what\n";
	}
	return 0;
}
void STNode::Get_FileP(ofstream* f)
{
	o = f;
}
NodeType STNode::GetNodeType() {
	return m_nodeType;
}

string STNode::GetGraphvizLabel() {
	return m_graphvizLabe1;
}