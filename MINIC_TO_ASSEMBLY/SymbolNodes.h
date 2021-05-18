#pragma once
#include "STNode.h"

//******************************BEGIN**********************************
class CCompileUnit : public STNode
{
public:
	CCompileUnit();
	virtual ~CCompileUnit();
	void Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent) override;
};

class CStatements : public STNode
{
public:
	CStatements();
	virtual ~CStatements();
//	int Visit_Eval() override;
};

class CStatement : public STNode
{
public:
	CStatement();
	virtual ~CStatement();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};
//******************************ADD/SUB/MUL/DIV/MOD**********************
class CAddition : public STNode
{
public:

	CAddition();
	virtual ~CAddition();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CSubtraction : public STNode
{
public:
	CSubtraction();
	virtual ~CSubtraction();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CMultiplication : public STNode
{
public:
	CMultiplication();
	virtual ~CMultiplication();
	int Visit_Eval() override;
	//void Visit_GenAssembly(ofstream* dotFile, NodeType info) override;
};

class CDivision : public STNode
{
public:
	CDivision();
	virtual ~CDivision();
	int Visit_Eval() override;
};

class CModulo : public STNode
{
public:
	CModulo();
	virtual ~CModulo();
	int Visit_Eval() override;
};

class CInc : public STNode
{
	/*
	INC and DEC Instructions SEL 15
	*/
public:
	CInc(int info);
	virtual ~CInc();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
private:
	int m_way;
};

class CDcr : public STNode
{
public:
	CDcr(int info);
	virtual ~CDcr();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
private:
	int m_way;
};
//***********************NOT/BIT NOT******************************

class CNot : public STNode
{

	// NEG Instruction (?) SEL 19 EPISHS
public:
	CNot();
	virtual ~CNot();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CBit_Not : public STNode
{
public:
	CBit_Not();
	virtual ~CBit_Not();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

//**************************** COMPARISON OPERATORS ************************ 

class CBigger : public STNode
{
public:
	CBigger();
	virtual ~CBigger();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CSmaller : public STNode
{
public:
	CSmaller();
	virtual ~CSmaller();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CBigger_Eq : public STNode
{
public:
	CBigger_Eq();
	virtual ~CBigger_Eq();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CSmaller_Eq : public STNode
{
public:
	CSmaller_Eq();
	virtual ~CSmaller_Eq();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CEq : public STNode
{
public:
	CEq();
	virtual ~CEq();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CNot_Eq : public STNode
{
public:
	CNot_Eq();
	virtual ~CNot_Eq();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CLogical_And : public STNode
{
public:
	CLogical_And();
	virtual ~CLogical_And();
	int Visit_Eval() override;
	//void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CLogical_Or
	
	
	
	
	: public STNode
{
public:
	CLogical_Or();
	virtual ~CLogical_Or();
	int Visit_Eval() override;
	//void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

//*****************************BIT LOGICAL OPERATORS ************************

class CBit_And : public STNode
{
public:
	CBit_And();
	virtual ~CBit_And();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CBit_Or : public STNode
{
public:
	CBit_Or();
	virtual ~CBit_Or();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CBit_Xor : public STNode
{
public:
	CBit_Xor();
	virtual ~CBit_Xor();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

//**********************TERMATIKA**********************

class CNUMBER : public STNode
{
public:

	int m_number;
	CNUMBER(char* text);
	virtual ~CNUMBER();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CREAL_NUMBER :public STNode {

public:
	double mr_number;
	CREAL_NUMBER(char* text);
	virtual ~CREAL_NUMBER();

	int Visit_Eval() override;

};

class CSTRING : public STNode {
public:
	string m_string;
	CSTRING(char* text);
	virtual ~CSTRING();
	int Visit_Eval() override;
};

class CIDENTIFIER : public STNode{

public:
	int m_number;
	string m_name;
	CIDENTIFIER(char* text);
	virtual ~CIDENTIFIER();

	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

//************************ASSIGNMENT****************************

class CAssignment : public STNode {
public:
	CAssignment();
	virtual ~CAssignment();

	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;


};

//***************************LOOPS****************************

class CWhile : public STNode {
public:
	CWhile();
	virtual ~CWhile();

	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CFor : public STNode {
public:
	CFor();
	virtual ~CFor();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

class CDo_While : public STNode {
public:
	CDo_While();
	virtual ~CDo_While();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
};

//**************************IF STATEMENTS**********************

class CIf_telesths : public STNode {
	
public:
	CIf_telesths();
	virtual ~CIf_telesths();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;

};

class CIf_statement : public STNode {
public:
	
	CIf_statement();
	virtual ~CIf_statement();
	int Visit_Eval() override;
	void Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) override;
	 
};

//*****************EXTRA FOR LOOPS AND FOR IF*********************

class CCompound : public STNode {
public:
	CCompound();
	virtual ~CCompound();

};

class CInsideList :public STNode {
public:
	CInsideList();
	virtual ~CInsideList();
};

//*****************PRINTF**********************

class CPrintf : public STNode {
	char m_str;
public:
	CPrintf(char text);
	virtual ~CPrintf();
	int Visit_Eval() override;
};

