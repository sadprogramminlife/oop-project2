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

	for (int i = 0; i < l->getAvailableLanterns().size(); i++)
		cout << l->getAvailableLanterns()[i].getInfo();


	auto items = l->getAvailableTents();
	cout <<l->performBorrowEquipment("T002", items);
	cout << endl;
	cout << l->performReturnEquipment("T002", items);

	return 0;
}