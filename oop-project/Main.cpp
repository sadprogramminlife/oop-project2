#include <iostream>
#include <string>
#include <vector>
#include "Initialization.h"
#include "LoanControl.h"
#include "User.h"
#include "Equipment.h"

int main() {
	bool isAdmin, isUser;
	std::string a = "SCM002";
	std::string b = "02111987";
	Initialization i(a, b, isAdmin, isUser);
	i.getLanterns();

	LoanControl *l = static_cast<LoanControl*>(&i);

	for (int i = 0; i < l->getAvailableTents().size(); i++)
		cout << l->getAvailableTents()[i].getInfo();

	cout << endl;

	for (int i = 0; i < l->getUserLoanRecords().size(); i++)
		cout << l->getUserLoanRecords()[i].getLoanRecord();

	
	l->performReturnEquipment("T002", );


	return 0;
}