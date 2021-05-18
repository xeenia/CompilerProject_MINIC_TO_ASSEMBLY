#include "SymbolNodes.h"
#include <iostream>
#include "SymbolTable.h"
#include "ReservationTable.h"
CCompileUnit::CCompileUnit() : STNode(NodeType::NT_COMPILEUNIT) {}
CCompileUnit::~CCompileUnit() {}
//**************************

//**********************
CStatements::CStatements() : STNode(NodeType::NT_STATEMENTS) {}
CStatements::~CStatements() {}
CInsideList::CInsideList() : STNode(nodeType::NT_INSIDELIST) {}
CInsideList::~CInsideList() {}
CStatement::CStatement() : STNode(NodeType::NT_STATEMENT) {}
CStatement::~CStatement() {}

CFor::CFor():STNode(NodeType::NT_FOR) {}
CFor::~CFor() {}

CDo_While::CDo_While() : STNode(NodeType::NT_DO_WHILE) {}
CDo_While::~CDo_While() {}

CIf_statement::CIf_statement() : STNode(NodeType::NT_IF_STATEMENT) {}
CIf_statement::~CIf_statement() {}
CAddition::CAddition() : STNode(NodeType::NT_EXPRESSION_ADDITION) {}
CAddition::~CAddition() {}

CIf_telesths::CIf_telesths() : STNode(NodeType::NT_IF_TELESTHS) {}
CIf_telesths::~CIf_telesths() {}

CSubtraction::CSubtraction() : STNode(NodeType::NT_EXPRESSION_SUBTRACTION) {}
CSubtraction::~CSubtraction() {}

CMultiplication::CMultiplication() : STNode(NodeType::NT_EXPRESSION_MULTIPLICATION) {}
CMultiplication::~CMultiplication() {}

CWhile::CWhile() : STNode(NodeType::NT_EXPRESSION_WHILE) {}
CWhile::~CWhile() {}

CDivision::CDivision() : STNode(NodeType::NT_EXPRESSION_DIVISION) {}
CDivision::~CDivision() {}

CNot::CNot() : STNode(NodeType::NT_EXPRESSION_NOT) {}
CNot::~CNot() {}

CBit_Not::CBit_Not() : STNode(NodeType::NT_EXPRESSION_BIT_NOT) {}
CBit_Not::~CBit_Not() {}

CBigger::CBigger() : STNode(NodeType::NT_EXPRESSION_BIGGER) {}
CBigger::~CBigger() {}

CModulo::CModulo() : STNode(NodeType::NT_EXPRESSION_MODULO) {}
CModulo::~CModulo() {}

CSmaller::CSmaller() : STNode(NodeType::NT_EXPRESSION_SMALLER) {}
CSmaller::~CSmaller() {}


CBit_And::CBit_And() : STNode(NodeType::NT_EXPRESSION_BIT_AND) {}
CBit_And::~CBit_And() {}

CBit_Or::CBit_Or() : STNode(NodeType::NT_EXPRESSION_BIT_OR) {}
CBit_Or::~CBit_Or() {}

CBit_Xor::CBit_Xor() : STNode(NodeType::NT_EXPRESSION_BIT_XOR) {}
CBit_Xor::~CBit_Xor() {}

CCompound::CCompound() : STNode(NodeType::NT_EXPRESSION_COMPOUND) {}
CCompound::~CCompound() {}

//-------------------------------------------------------------------------------------

CBigger_Eq::CBigger_Eq() : STNode(NodeType::NT_EXPRESSION_BIGGER_EQ) {}
CBigger_Eq::~CBigger_Eq() {}

CSmaller_Eq::CSmaller_Eq() : STNode(NodeType::NT_EXPRESSION_SMALLER_EQ) {}
CSmaller_Eq::~CSmaller_Eq() {}

CInc::CInc(int info) : STNode(NodeType::NT_EXPRESSION_INC) {
	m_way = info;
}
CInc::~CInc() {}

CDcr::CDcr(int info) : STNode(NodeType::NT_EXPRESSION_DCR) {
	m_way = info;
}
CDcr::~CDcr() {}


CEq::CEq() : STNode(NodeType::NT_EXPRESSION_EQ) {}
CEq::~CEq() {}

CNot_Eq::CNot_Eq() : STNode(NodeType::NT_EXPRESSION_NOT_EQ) {}
CNot_Eq::~CNot_Eq() {}

CLogical_And::CLogical_And() : STNode(NodeType::NT_EXPRESSION_LOGICAL_AND) {}
CLogical_And::~CLogical_And() {}

CLogical_Or::CLogical_Or() : STNode(NodeType::NT_EXPRESSION_LOGICAL_OR) {}
CLogical_Or::~CLogical_Or() {}

CNUMBER::CNUMBER(char* text) : STNode(NodeType::NT_EXPRESSION_NUMBER) {
	m_number = atoi(text);
	m_graphvizLabe1.append("_" + std::to_string(m_number));
}
CNUMBER::~CNUMBER() {}

CSTRING::CSTRING(char* text) : STNode(nodeType::NT_STRING) {
	m_string = text;
	m_graphvizLabe1.append("_" + m_string);
}
CSTRING::~CSTRING() {}

CPrintf::CPrintf(char text) : STNode(nodeType::NT_PRINTF) {
	m_str = text;
}
CPrintf::~CPrintf() {}
//*********************





//**********************
CIDENTIFIER::CIDENTIFIER(char* text): STNode(NodeType::NT_EXPRESSION_IDENTIFIER){
	m_name = (string)text;
	m_number = 0;
	m_graphvizLabe1.append("_" + m_name);
}
CIDENTIFIER::~CIDENTIFIER() {}
int CIDENTIFIER::Visit_Eval() {
	return m_number;
}
CAssignment::CAssignment(): STNode(NodeType::NT_EXPRESSION_ASSIGNMENT) {
}
CAssignment::~CAssignment() {}

int CAssignment::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
	advance(it, 1);
	id->m_number = (*it)->Visit_Eval();
	cout << id->m_name << "=" << id->m_number << endl;
	return id->m_number;
}

void CCompileUnit::Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent) {
	list<STNode*>::iterator it;
	if (parent == nullptr) {
		(*dotFile) << "digraph G{ \n";
		for (it = m_children->begin(); it != m_children->end(); it++) {
			(*it)->Visit_SyntaxTreePrinter(dotFile, this);
		}
		(*dotFile) << "}";
		dotFile->close();
	}
	else {
		STNode::Visit_SyntaxTreePrinter(dotFile, this);
	}
}
int CStatement::Visit_Eval() {
	list<STNode*>::iterator it;
	if (m_children->size() != 0) {
		it = m_children->begin();
		cout << "Result: " << (*it)->Visit_Eval() << endl;
	}
	return 0;
}
int CNUMBER::Visit_Eval() {
	return m_number;
}
int CSTRING::Visit_Eval() {
	return 0;
}
int CPrintf::Visit_Eval() {
	cout << m_str;
	return 0;
}
int CAddition::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result += (*it)->Visit_Eval();
	return result;
}
int CSubtraction::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result -= (*it)->Visit_Eval();
	return result;
}
int CMultiplication::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result *= (*it)->Visit_Eval();
	return result;
}
int CDivision::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result /= (*it)->Visit_Eval();
	return result;
}

int CModulo::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result %= (*it)->Visit_Eval();
	return result;
}
int CNot::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = !(*it)->Visit_Eval();
	return result;
}
int CBit_Not::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result;
	result = ~(*it)->Visit_Eval();
	return result;
}
int CBigger::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result > (*it)->Visit_Eval();
	return result;
}
int CSmaller::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result < (*it)->Visit_Eval();
	return result;
}
int CBit_And::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result &= (*it)->Visit_Eval();
	return result;
}



int CBit_Or::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result |= (*it)->Visit_Eval();
	return result;
}
int CBit_Xor::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result ^= (*it)->Visit_Eval();
	return result;
}
int CBigger_Eq::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result >= (*it)->Visit_Eval();
	return result;
	
}
int CSmaller_Eq::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result <= (*it)->Visit_Eval();
	return result;
}


int CInc::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result;
	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
	//advance(it, 1);
	result = id->m_number;
	if (m_way)
		result = ++id->m_number;
	else
		result = id->m_number++;
	return result;
	
}
int CDcr::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result;
	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
//	advance(it, 1);
	result = id->m_number;
	if (m_way)
		result = --id->m_number;
	else
		result = id->m_number--;
	return result;
}


int CEq::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result == (*it)->Visit_Eval();
	return result;
}
int CNot_Eq::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result != (*it)->Visit_Eval();
	return result;
}
int CLogical_And::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result && (*it)->Visit_Eval();
	return result;
}
int CLogical_Or::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	advance(it, 1);
	result = result || (*it)->Visit_Eval();
	return result;
}

int CWhile::Visit_Eval() {
	while (GetChild(0)->Visit_Eval()) {
		GetChild(1)->Visit_Eval();
	}
	return 0;
}
int CFor::Visit_Eval() {
	for (GetChild(0)->Visit_Eval(); GetChild(1)->Visit_Eval(); GetChild(2)->Visit_Eval()) {
		GetChild(3)->Visit_Eval();
	}
	return 0;
}
int CIf_telesths::Visit_Eval() {
	int i;
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->Visit_Eval();
	i=(result) ? (advance(it, 1), (*it)->Visit_Eval()) : (advance(it, 2), (*it)->Visit_Eval());
	cout << i << "\n";
	return i;
}
int CIf_statement::Visit_Eval() {
	list<STNode*>::iterator it = m_children->begin();
	int i=m_children->size();
	int result = (*it)->Visit_Eval();
	if (i == 2) {
		if (result) {
			advance(it, 1);
			(*it)->Visit_Eval();
		}
	}
	else if (i == 3) {
		if (result) {
			advance(it, 1);
			(*it)->Visit_Eval();
		}
		else {
			advance(it, 2);
			(*it)->Visit_Eval();
		}
	}
	return 0;
 }

int CDo_While::Visit_Eval() {
	do {
		GetChild(0)->Visit_Eval();
	} while (GetChild(1)->Visit_Eval());
	return 0;
}






























