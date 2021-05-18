#include "SymbolNodes.h"
#include <iostream>
#include "SymbolTable.h"
#include "ReservationTable.h"

void CStatement::Visit_GetIdentifier(ofstream* dotFile) {
	list<STNode*>::iterator it;
	//(*dotFile) << "MOV EAX, 0\n";
	if (m_children->size() != 0) {
		it = m_children->begin();
		(*it)->Visit_GetIdentifier(dotFile);
	}

}
void CAssignment::Visit_GetIdentifier(ofstream* dotFile) {
	list<STNode*>::iterator it = m_children->begin();
	(*it)->Visit_GetIdentifier(dotFile);
}

void CIDENTIFIER::Visit_GetIdentifier(ofstream* dotFile) {
	(*dotFile) << m_name << " DWORD ?"  <<endl;

}