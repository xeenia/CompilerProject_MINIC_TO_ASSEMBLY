#include "SymbolNodes.h"
#include <iostream>
#include "SymbolTable.h"
#include "ReservationTable.h"

//******************************STATEMENT*****************************************

void CStatement::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it;
	if (m_children->size() != 0) {
		it = m_children->begin();
		(*it)->Visit_GenAssembly(dotFile, info, "0");
	}

}

//******************************ASSIGNMENT*****************************************

void CAssignment::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
	NodeType nodetype = GetChild(1)->GetNodeType();

	if (nodetype ==NT_EXPRESSION_NUMBER) { //id = num;
		string current_reg = g_reservationTable.GetRegister(0); 
		advance(it, 1);
		(*dotFile) << "\tMOV " << id->m_name << ",";
		(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
	}
	else if(nodetype==NT_EXPRESSION_IDENTIFIER){ //id = id;
		string current_reg = g_reservationTable.GetRegister(0);	
		(*dotFile) << "\tMOV " << current_reg << ","; //mov eax, id
		advance(it, 1);
		(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
		(*dotFile) << endl;
		(*dotFile) << "\tMOV " << id->m_name << "," << current_reg << endl; //mov id,eax
	}
	else { //alles periptwseis
		string current_reg = g_reservationTable.GetRegister(0);
		int i = GetChild(1)->GetNodeType() == NT_EXPRESSION_BIT_OR || GetChild(1)->GetNodeType() == NT_EXPRESSION_BIT_AND || GetChild(1)->GetNodeType() == NT_EXPRESSION_BIT_XOR;
		if (i) {
			(*dotFile) << "\tMOV " << current_reg << ",";
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
		}
		else {
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
			
		}
		(*dotFile) << "\tMOV " << id->m_name << ",";
		(*dotFile) << current_reg << endl;
		
		
		
		
		
	}

	
}

//******************************NUMBER AND ID*****************************************
void CNUMBER::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	(*dotFile)  << m_number << endl;
	g_reservationTable.ReturnRegister(reg);
}

void CIDENTIFIER::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	(*dotFile) << m_name;
	g_reservationTable.ReturnRegister(reg); 
}

//******************************ADD AND SUB*****************************************

void CAddition::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	if((*it)->GetNodeType()==NT_EXPRESSION_NUMBER|| (*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << "\tADD " << reg << ",";
	
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		(*dotFile) << endl;
	}
	(*dotFile) << "\tADD " << reg << ",";		
	advance(it, 1);
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		(*dotFile) << endl;
	}

}

void CSubtraction::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER || (*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << "\tSUB1 " << reg << ",";

	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		(*dotFile) << endl;
	}
	(*dotFile) << "\tSUB2 " << reg << ",";
	advance(it, 1);
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		(*dotFile) << endl;
	}

}

//******************************DCR AND ICR*****************************************

void CDcr::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
	(*dotFile) << "\tDCR " << id->m_name << endl;
	if (info == NT_DO_WHILE || info == NT_EXPRESSION_WHILE) {
		(*dotFile) << "\tCMP " << id->m_name << ",0\n";
		(*dotFile) << "\tJZ ";
	}
}

void CInc::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
	(*dotFile) << "\tINC " << id->m_name << endl;
	if (info == NT_DO_WHILE || info == NT_EXPRESSION_WHILE) {
		(*dotFile) << "\tCMP " << id->m_name << ",0\n";
		(*dotFile) << "\tJZ ";
	}

}

//******************************** NOT ***************************************

void CNot::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
		(*dotFile) << "\tMOV " << reg << ",";
		if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*it)->Visit_GenAssembly(dotFile, info, reg);
		}
		else {
			CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
			(*dotFile) << id->m_name << "\n";
		}

		(*dotFile) << "\tCMP " << reg << ",0\n";
		(*dotFile) << "\tJE not_telesths_0\n";
		(*dotFile) << "\tMOV " << reg << ",1\n";
		(*dotFile) << "\tJMP not_telesths_1\n";
		(*dotFile) << "not_telesths_0:\n";
		(*dotFile) << "\tMOV " << reg << ",0\n";
		(*dotFile) << "not_telesths_1\n";
}


// ****************************** LOGICAL AND, XOR, OR, NOT ************************

void CBit_And::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << endl;
	advance(it, 1);
	
	(*dotFile) << "\tAND " << reg << ",";
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if((*it)->GetNodeType()==NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << endl;
}

void CBit_Or::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << endl;
	advance(it, 1);
	
	(*dotFile) << "\tOR " << reg << ",";
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << endl;
}

void CBit_Xor::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << endl;
	advance(it, 1);
	
	(*dotFile) << "\tXOR " << reg << ",";
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
		(*dotFile) << endl;
}

void CBit_Not::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
		(*dotFile) << "\tMOV " << reg << ",";
		(*it)->Visit_GenAssembly(dotFile, info, reg);
		(*dotFile) << "\tNOT " << reg << endl;
	}
	else {
		CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
		(*dotFile) << "\tNOT " << id->m_name << endl;
	}

}

//********************************	LOOPS ********************************

void CWhile::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int flag = c_while_flag++;
	(*dotFile) << "startWhile_"<< flag <<":\n";
	list<STNode*>::iterator it = m_children->begin();
	string current_reg = g_reservationTable.GetRegister(0);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
		(*dotFile) << "\tCMP " << id->m_name << ",0\n\tJE ";
	}else
		(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
	advance(it, 1);
	(*dotFile) << "endWhile_" << flag << "\n";
	(*it)->Visit_GenAssembly(dotFile, info, reg);
	(*dotFile) << "\tJMP startWhile_"<< flag <<"\n" <<"endWhile_"<< flag <<":\n";
}

void CDo_While::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int flag = c_do_while_flag++;
	list<STNode*>::iterator it = m_children->begin();
	string current_reg = g_reservationTable.GetRegister(0);
	(*dotFile) << "startDoWhile_" << flag <<":\n";
	(*it)->Visit_GenAssembly(dotFile, info, current_reg);
	advance(it, 1);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
		(*dotFile) << "\tCMP " << id->m_name << ",0\n\tJE ";
	}else
		(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
	(*dotFile) << " endDoWhile_" << flag <<"\n";
	(*dotFile) << "\tJMP startDoWhile_" << flag <<"\n";
	(*dotFile) << "endDoWhile_" << flag << ":\n";
}

void CFor::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int flag = c_for_flag++;
	list<STNode*>::iterator it = m_children->begin();
	string current_reg = g_reservationTable.GetRegister(0);
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		advance(it, 1);
	}
	else {
		(*it)->Visit_GenAssembly(dotFile, info, current_reg);
		advance(it, 1);
	}
	
	(*dotFile) << "startFor_" << flag << ":\n";
	if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
		CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
		(*dotFile) << "\tCMP " << id->m_name << ",0\n\tJE ";
	}else
		(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
	advance(it, 2);
	(*dotFile) << " endFor_" <<flag<<"\n";
	(*it)->Visit_GenAssembly(dotFile, info, current_reg);
	advance(it, -1);
	(*it)->Visit_GenAssembly(dotFile, info, current_reg);
	(*dotFile) << "\tJMP startFor_" <<flag<<"\n";
	(*dotFile) << "endFor_"<<flag<<":\n";

}

//************************** IF STATEMENTS **********************************

void CIf_statement::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	list<STNode*>::iterator it = m_children->begin();
	string current_reg = g_reservationTable.GetRegister(0);
	int i = m_children->size();
	if (i == 2) {
		int flag = c_if_st_flag;
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
			CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
			(*dotFile) << "\tCMP " << id->m_name << ",0\n\tJE ";
		}
		else if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << "\tMOV " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
			(*dotFile) << "\tCMP " << current_reg << ",0\n";
			(*dotFile) << "\tJE "; //???
		}else
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
		(*dotFile) << "ifFalse_" << flag << "\n";
		advance(it, 1);
		if ((*it)->GetNodeType() == NT_IF_STATEMENT)
			c_if_st_flag++;
		(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
		(*dotFile) << "ifFalse_" << flag <<":\n";
	}
	else if (i == 3) {
		int flag = c_if_else_st_flag;
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
			CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
			(*dotFile) << "\tCMP " << id->m_name << ",0\n\tJE ";
		}
		else if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << "\tMOV " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
			(*dotFile) << "\tCMP " << current_reg << ",0\n";
			(*dotFile) << "\tJE "; //???

		}
		else
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
		(*dotFile) << "ifElseFalse_" << flag << "\n";
		advance(it, 1);
		if ((*it)->GetNodeType() == NT_IF_STATEMENT)
			c_if_else_st_flag++;
		(*it)->Visit_GenAssembly(dotFile, info, current_reg);
		(*dotFile) << "\tJMP ifElseTrue_" << flag <<"\n";
		(*dotFile) << "ifElseFlase_" << flag << ":\n";
		advance(it, 1);
		if ((*it)->GetNodeType() == NT_IF_STATEMENT)
			c_if_else_st_flag++;
		(*it)->Visit_GenAssembly(dotFile, info, current_reg);
		(*dotFile) << "ifElseTrue_" << flag << ":\n";
	}
}

void CIf_telesths::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int flag = c_if_tel_flag++;
	list<STNode*>::iterator it = m_children->begin();
	string current_reg = g_reservationTable.GetRegister(0);
	if (m_children->size() == 3) { // ()?anathesh1:anathesh2;
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
			CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
			(*dotFile) << "\tCMP " << id->m_name << ",0\n\tJE ";
		}
		else if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << "\tMOV " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
			(*dotFile) << "\tCMP " << current_reg << ",0\n";
			(*dotFile) << "\tJE "; //???
		}else
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
		advance(it, 1);
		(*dotFile) << "A1_" << flag << "\n";
		(*it)->Visit_GenAssembly(dotFile, info, current_reg);
		advance(it, 1);
		(*dotFile) << "\tJMP A2_" << flag <<"\n";
		(*dotFile) << "A1_" << flag <<":\n";
		(*it)->Visit_GenAssembly(dotFile, info, current_reg);
		(*dotFile) << "A2_" << flag << ":\n";
	}
	else { // id = ()?:
		CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);
		string name = id->m_name;
		advance(it, 1);
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER) {
			CIDENTIFIER* id2 = dynamic_cast<CIDENTIFIER*>(*it);
			(*dotFile) << "\tCMP " << id2->m_name << ",0\n\tJE ";
		}
		else if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << "\tMOV " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg);
			(*dotFile) << "\tCMP " << current_reg << ",0\n";
			(*dotFile) << "\tJE "; //???
		}else
			(*it)->Visit_GenAssembly(dotFile, GetNodeType(), current_reg); //(exp)
		(*dotFile) << "A1\n";
		(*dotFile) << "\tMOV " << name << ",";
		advance(it, 1); //?exp:
		(*it)->Visit_GenAssembly(dotFile, info, current_reg);
		(*dotFile) << "\tJMP A2\n";
		advance(it, 1);
		(*dotFile) << "A1:\n";
		(*dotFile) << "\tMOV " << name << ",";
		(*it)->Visit_GenAssembly(dotFile, info, current_reg);
		(*dotFile) << "A2:\n";

	}
	
}

//************************** COMPARISONS ************************************

void CBigger::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int i = (info == NT_DO_WHILE) || (info == NT_EXPRESSION_WHILE) || (info == NT_FOR) || info == NT_IF_STATEMENT || info == NT_IF_TELESTHS;
	int j = GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER && GetChild(1)->GetNodeType() == NT_EXPRESSION_NUMBER;
	

	if (i&&(!j)) {
		list<STNode*>::iterator it = m_children->begin();
		if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			advance(it, 1);
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, -1);
			(*dotFile) << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);

		}
		else {
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			(*dotFile) << ",";
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, info, reg);
		}	
		
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
			(*dotFile) << endl;
		(*dotFile) << "\tJNA ";
	}
	else {
		list<STNode*>::iterator it = m_children->begin();
		//string current_reg = g_reservationTable.GetRegister(0);
		string current_reg = reg;
		(*dotFile) << "\tMOV ";
		if (GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, 1);
			(*dotFile) << "\tCMP " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			if (!j) {
				(*dotFile) << "\tJNA false_0\n";
				(*dotFile) << "\tMOV " << current_reg << ",1\n";
				(*dotFile) << "\tJMP true_1\n";
				(*dotFile) << "false_0:\n";
				(*dotFile) << "\tMOV " << current_reg << ",0\n";
				(*dotFile) << "true_1:\n";
			}
			else {
				(*dotFile) << "\tJNA ";
			}
			
		}
	}
}

void CSmaller::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int i = (info == NT_DO_WHILE) || (info == NT_EXPRESSION_WHILE) || (info == NT_FOR) || info == NT_IF_STATEMENT || info == NT_IF_TELESTHS;
	int j = GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER && GetChild(1)->GetNodeType() == NT_EXPRESSION_NUMBER;
	if (i && (!j)) {
		list<STNode*>::iterator it = m_children->begin();
		if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			advance(it, 1);
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, -1);
			(*dotFile) << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);

		}
		else {
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			(*dotFile) << ",";
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, info, reg);
		}
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
			(*dotFile) << "\n";
		(*dotFile) << "\tJNB ";
	}
	else {
		list<STNode*>::iterator it = m_children->begin();
		//string current_reg = g_reservationTable.GetRegister(0);
		string current_reg = reg;
		(*dotFile) << "\tMOV ";
		if (GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, 1);
			(*dotFile) << "\tCMP " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			if (!j) {
				(*dotFile) << "\tJNB false_0\n";
				(*dotFile) << "\tMOV " << current_reg << ",1\n";
				(*dotFile) << "\tJMP true_1\n";
				(*dotFile) << "false_0:\n";
				(*dotFile) << "\tMOV " << current_reg << ",0\n";
				(*dotFile) << "true_1:\n";
			}else
				(*dotFile) << "\tJNB ";
			
		}

	}
	
}

void CBigger_Eq::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int i = (info == NT_DO_WHILE) || (info == NT_EXPRESSION_WHILE) || (info == NT_FOR) || info == NT_IF_STATEMENT || info == NT_IF_TELESTHS;
	int j = GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER && GetChild(1)->GetNodeType() == NT_EXPRESSION_NUMBER;
	if (i && (!j)) {
		list<STNode*>::iterator it = m_children->begin();
		if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			advance(it, 1);
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, -1);
			(*dotFile) << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);

		}
		else {
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			(*dotFile) << ",";
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, info, reg);
		}
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
			(*dotFile) << "\n";
		(*dotFile) << "\tJNAE ";
	}
	else {
		list<STNode*>::iterator it = m_children->begin();
		//string current_reg = g_reservationTable.GetRegister(0);
		string current_reg = reg;
		(*dotFile) << "\tMOV ";
		if (GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, 1);
			(*dotFile) << "\tCMP " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			if (!j) {
				(*dotFile) << "\tJNAE false_0\n";
				(*dotFile) << "\tMOV " << current_reg << ",1\n";
				(*dotFile) << "\tJMP true_1\n";
				(*dotFile) << "false_0:\n";
				(*dotFile) << "\tMOV " << current_reg << ",0\n";
				(*dotFile) << "true_1:\n";
			}else
				(*dotFile) << "\tJNAE ";
			
		}
	}
	
}

void CSmaller_Eq::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int i = (info == NT_DO_WHILE) || (info == NT_EXPRESSION_WHILE) || (info == NT_FOR) || info == NT_IF_STATEMENT || info == NT_IF_TELESTHS;
	int j = GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER && GetChild(1)->GetNodeType() == NT_EXPRESSION_NUMBER;
	if (i && (!j)) {
		list<STNode*>::iterator it = m_children->begin();
		if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			advance(it, 1);
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, -1);
			(*dotFile) << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);

		}
		else {
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			(*dotFile) << ",";
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, info, reg);
		}
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
			(*dotFile) << "\n";
		(*dotFile) << "\tJNBE ";
	}
	else {
		list<STNode*>::iterator it = m_children->begin();
		//string current_reg = g_reservationTable.GetRegister(0);
		string current_reg = reg;
		(*dotFile) << "\tMOV ";
		if (GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, 1);
			(*dotFile) << "\tCMP " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			if (!j) {
				(*dotFile) << "\tJNBE false_0\n";
				(*dotFile) << "\tMOV " << current_reg << ",1\n";
				(*dotFile) << "\tJMP true_1\n";
				(*dotFile) << "false_0:\n";
				(*dotFile) << "\tMOV " << current_reg << ",0\n";
				(*dotFile) << "true_1:\n";
			}else
				(*dotFile) << "\tJNBE ";
		
		}
	}
}

void CEq::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int i = (info == NT_DO_WHILE) || (info == NT_EXPRESSION_WHILE) || (info == NT_FOR) || info == NT_IF_STATEMENT || info == NT_IF_TELESTHS;
	int j = GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER && GetChild(1)->GetNodeType() == NT_EXPRESSION_NUMBER;
	if (i && (!j)) {
		list<STNode*>::iterator it = m_children->begin();
		if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			advance(it, 1);
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, -1);
			(*dotFile) << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);

		}
		else {
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			(*dotFile) << ",";
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, info, reg);
		}
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
			(*dotFile) << "\n";
		(*dotFile) << "\tJNE ";
	}
	else {
		list<STNode*>::iterator it = m_children->begin();
		//string current_reg = g_reservationTable.GetRegister(0);
		string current_reg = reg;
		(*dotFile) << "\tMOV ";
		if (GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, 1);
			(*dotFile) << "\tCMP " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			if (!j) {
				(*dotFile) << "\tJNE false_0\n";
				(*dotFile) << "\tMOV " << current_reg << ",1\n";
				(*dotFile) << "\tJMP true_1\n";
				(*dotFile) << "false_0:\n";
				(*dotFile) << "\tMOV " << current_reg << ",0\n";
				(*dotFile) << "true_1:\n";
			}else
				(*dotFile) << "\tJNE ";
			
		}
	}
	
}

void CNot_Eq::Visit_GenAssembly(ofstream* dotFile, NodeType info, string reg) {
	int i = (info == NT_DO_WHILE) || (info == NT_EXPRESSION_WHILE) || (info == NT_FOR) || info == NT_IF_STATEMENT || info == NT_IF_TELESTHS;
	int j = GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER && GetChild(1)->GetNodeType() == NT_EXPRESSION_NUMBER;
	if (i && (!j)) {
		list<STNode*>::iterator it = m_children->begin();
		if ((*it)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			advance(it, 1);
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, -1);
			(*dotFile) << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);

		}
		else {
			(*dotFile) << "\tCMP ";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			(*dotFile) << ",";
			advance(it, 1);
			(*it)->Visit_GenAssembly(dotFile, info, reg);
		}
		if ((*it)->GetNodeType() == NT_EXPRESSION_IDENTIFIER)
			(*dotFile) << "\n";
		(*dotFile) << "\tJE ";
	}
	else {
		list<STNode*>::iterator it = m_children->begin();
		//string current_reg = g_reservationTable.GetRegister(0);
		string current_reg = reg;
		(*dotFile) << "\tMOV ";
		if (GetChild(0)->GetNodeType() == NT_EXPRESSION_NUMBER) {
			(*dotFile) << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			advance(it, 1);
			(*dotFile) << "\tCMP " << current_reg << ",";
			(*it)->Visit_GenAssembly(dotFile, info, reg);
			if (!j) {
				(*dotFile) << "\tJE false_0\n";
				(*dotFile) << "\tMOV " << current_reg << ",1\n";
				(*dotFile) << "\tJMP true_1\n";
				(*dotFile) << "false_0:\n";
				(*dotFile) << "\tMOV " << current_reg << ",0\n";
				(*dotFile) << "true_1:\n";
			}else
				(*dotFile) << "\tJE ";
			
		}
	}
}

//********************************* LOGICAL OR *********************************

