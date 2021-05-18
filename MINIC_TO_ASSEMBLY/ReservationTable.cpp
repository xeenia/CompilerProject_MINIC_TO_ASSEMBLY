#include "ReservationTable.h"
#include <iostream>
#include <fstream>
ReservationTable g_reservationTable;
 ReservationTable::ReservationTable() {

	map<string, int>::iterator it;
	
	int i = 0;
	string line;
	ifstream myREGfile("reg.txt");
	while (getline(myREGfile, line)) {
		a_registers[line] = 1;
	}
	
}

 string ReservationTable::GetRegister(int number) {
	 map<string, int>::iterator it = a_registers.begin();
	 string n = "none";
	 while (1)
	 {
		
		 if ((*it).second) {
			 n = (string)(*it).first;
			 (*it).second = 0;
			 return n;
		 }
		 if (it == a_registers.end())
			 break;
		 advance(it, 1);
		 
	 }
	 return "none1";
 }

void ReservationTable::ReturnRegister(string name) {
	// map<string, int>::iterator it;
	 a_registers[name] = 1;  
 }