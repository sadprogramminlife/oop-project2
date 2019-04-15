#include "System.h"


void system() {

	while (true) {
		bool isUser, isAdmin;
		string username, password;
		cout << "Enter your username: ";
		cin >> username;

		if (!username.compare("-1"))
			break;

		cout << "Enter your password: ";
		cin >> password;

		Initialization h(username, password, isAdmin, isUser);

		if (isAdmin) {

			Admin *a = static_cast<Admin*>(&h);

			bool isExit = false;
			do {


				int choice;

				cout << "1. Display Loan Record" << endl;
				cout << "2. Display Equipments" << endl;
				cout << "3. Change equipment condition" << endl;

				cout << "Please the choice's number" << endl;
				cin >> choice;
				if (choice > 0 && choice < 4) {

					adminMenu(choice, a);
				}
				else if (choice == -1) {
					isExit = true;
				}

			} while (!isExit);
		}
		else if (isUser) {
			LoanControl *a = static_cast<LoanControl*>(&h);
			User *user = a->getUser();

			bool isExit = false;
			do {
				int choice;

				cout << "1. Display Avaliable Equipment" << endl;
				cout << "2. Diplay User's Loan Record"<< endl;
				if (user->isAllow())
					cout << "3. Borrow Equipment" << endl;
				cout << "4. Return Equipment" << endl;

				cout << "Please the choice's number" << endl;
				cin >> choice;
				if (choice > 0 && choice < 5) {
					menu(choice, a);
				}
				else if (choice == -1) {
					isExit = true;
				}

			} while (!isExit);
		}



	}
}

void menu(int n, LoanControl * a)
{
	User *user = a->getUser();
	vector<LoanRecord> ur = a->getUserLoanRecords();
	vector<Tent> t = a->getTents();
	vector<Stove> s = a->getStoves();
	vector<Lantern> l = a->getLanterns();

	vector<Tent> at = a->getAvailableTents();
	vector<Stove> as = a->getAvailableStoves();
	vector<Lantern> al = a->getAvailableLanterns();

	string eid;
	bool can = false;

	switch (n) {
	case 1:
		for (int i = 0; i < at.size(); i++) {
			cout << at[i].getInfo();
		}
		cout << endl;
		for (int i = 0; i < as.size(); i++) {
			cout << as[i].getInfo();
		}
		cout << endl;
		for (int i = 0; i < al.size(); i++) {
			cout << al[i].getInfo();
		}
		cout << endl;

		system("pause");

		break;
	case 2:
		for (int i = 0; i < ur.size(); i++) {
			cout << ur[i].getLoanRecord();
		}

		system("pause");

		break;
	case 3:
		cout << "Borrow" << endl;

		while (true) {
			cout << "Enter -1 to exit" << endl;
			cout << "Enter the Equipment ID ";
			cin >> eid;

			if (eid[0] == 'T') {
				can = a->performBorrowEquipment(eid, t);
			}
			else if (eid[0] == 'S')
			{
				can = a->performBorrowEquipment(eid, s);
			}
			else if (eid[0] == 'L')
			{
				can = a->performBorrowEquipment(eid, l);
			} else if (!eid.compare("-1")) {

				break;
			}

			if (!can)
				cout << "equipment not existed or user exceed the limit for borrowing item" << endl;
			else {
				cout << "borrow success" << endl;
			}
		}

		break;
	case 4:
		cout << "Return" << endl;

		while (true) {
			cout << "Enter -1 to exit" << endl;
			cout << "Enter the Equipment ID ";
			cin >> eid;

			if (eid[0] == 'T') {
				can = a->performReturnEquipment(eid, t);
			}
			else if (eid[0] == 'S')
			{
				can = a->performReturnEquipment(eid, s);
			}
			else if (eid[0] == 'L')
			{
				can = a->performReturnEquipment(eid, l);
			}
			else if (!eid.compare("-1")) {

				break;
			}

			if (!can)
				cout << "equipment not existed" << endl;
			else {
				cout << "return success" << endl;
			}
		}

		break;
	}
}

void adminMenu(int n, Admin *a) {


	vector<LoanRecord> r = a->getLoanRecord();
	vector<Tent> t = a->getTents();
	vector<Stove> s = a->getStoves();
	vector<Lantern> l = a->getLanterns();

	switch (n) {
	case 1:
		for (int i = 0; i < r.size(); i++) {
			cout << r[i].getLoanRecord();
		}
		system("pause");

		break;
	case 2:
		for (int i = 0; i < t.size(); i++) {
			cout << t[i].getInfo();
		}
		cout << endl;
		for (int i = 0; i < s.size(); i++) {
			cout << s[i].getInfo();
		}
		cout << endl;
		for (int i = 0; i < l.size(); i++) {
			cout << l[i].getInfo();
		}
		cout << endl;

		system("pause");

		break;
	case 3:
		string eid, condition;
		cout << "Enter the equipment id: ";
		cin >> eid;
		cout << "Enter the new condition";
		cin >> condition;

		if (a->updateEquipCcondition(eid, condition)) {
			cout << "Update Success" << endl;
		}
		else {
			cout << "Invalid EID Or Conditon" << endl;
		}

		break;
	}
}

