#pragma once

#include <map>
#include <string>
#include "SymbolNodes.h"
using namespace std;

class ReservationTable{
public:
	map<string, int> a_registers;

	ReservationTable();
	string GetRegister(int number);
	void ReturnRegister(string name);
	//void f(string* name);
private:

};
extern ReservationTable g_reservationTable;