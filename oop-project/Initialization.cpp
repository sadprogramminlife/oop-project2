#include "Initialization.h"



Initialization::Initialization()
{
}


Initialization::~Initialization()
{
	// delete objects
	for (int i = 0; i < users.size(); i++) {
		delete users[i];
	}
}

Initialization::Initialization(std::string username, std::string password, bool &isAdmin, bool &isUser)
{
	insertUser();

	isAdmin = false;
	isUser = false;

	if ( username.compare("admin") || password.compare("admin") ) {			// return 1 if user is not admin
		for (int i = 0; i < users.size(); i++) {
			if (!username.compare((this->users)[i]->getId()) && !password.compare((this->users)[i]->getDob())) {
				isUser = true;
				this->index_of_user = i;

				break;
			}
		}
	}
	else {
		this->index_of_user = -1;
		isAdmin = true;
	}

	if (isAdmin ^ isUser) {
		insertEquip();
		insertRecord();

		if (isUser) {
			for (int i = 0; i < records.size(); i++) {
				string match_uid = records[i].getUserId();

				if (!match_uid.compare(getUser()->getId())) {
					string match_eid = records[i].getEquipId();
					bool isLoan = true;
					for (int j = i + 1; isLoan && j < records.size(); j++) {
						if (!records[j].getUserId().compare(match_uid))
							if (!records[j].getEquipId().compare(match_uid))
								if (!records[j].getStatus().compare("out for loan"))
									isLoan = false;
					}

					if (isLoan)
						getUser()->borrowItem(match_eid);
				}
			}
		}
	}
}

void Initialization::insertUser(std::string path)
{
	stringstream ac = (stringstream)fileRead(path);
	string line;

	while (getline(ac, line))
	{
		string id, name, section, date, address, rank;
		stringstream ss(line);

		
		if ((ss.rdbuf()->in_avail()))
		{
			getline(ss, id, '|');
			getline(ss, name, '|');
			getline(ss, section, '|');
			getline(ss, date, '|');
			getline(ss, address, '|');

			if (!ss.eof())
			{
				getline(ss, rank, '|');
			}

			if (id.substr(0, 3) == "VEN")
			{
				this->users.push_back(new VentureScout(id, name, section, date, address));
			}
			else if (id.substr(0, 3) == "ROV")
			{
				this->users.push_back(new RoverScout(id, name, section, date, address));
			}
			else if (id.substr(0, 3) == "SCT")
			{
				this->users.push_back(new Scout(id, name, section, date, address, rank));
			}
			else if (id.substr(0, 3) == "SCM")
			{
				this->users.push_back(new Scouter(id, name, section, date, address, rank));
			}
		}
	}

	updateUser();
}

void Initialization::insertEquip(std::string path)
{
	stringstream text = (stringstream)fileRead(path);
	string line;
	while (getline(text, line))
	{
		string  itemID, itemName, brand, itemType, dateOfPurchase, condition, status;
		stringstream ssline = (stringstream)line;

		getline(ssline, itemID, '|');
		getline(ssline, itemName, '|');
		getline(ssline, brand, '|');
		getline(ssline, itemType, '|');
		getline(ssline, dateOfPurchase, '|');
		getline(ssline, condition, '|');
		getline(ssline, status, '|');

		if (itemID.substr(0, 1) == "T")
		{
			string tentSize, tentType, numberOfDoors, isDoubleLayer, colour;
			getline(ssline, tentSize, '|');
			getline(ssline, tentType, '|');
			getline(ssline, numberOfDoors, '|');
			getline(ssline, isDoubleLayer, '|');
			getline(ssline, colour, '|');
			this->tents.push_back(Tent(itemID, itemName, brand, itemType, dateOfPurchase, condition, status, tentSize, tentType, numberOfDoors, isDoubleLayer, colour));

		}
		else if (itemID.substr(0, 1)[0] == 'L')
		{
			string fuelType;
			string lanternType;
			string lanternSize;
			getline(ssline, fuelType, '|');
			getline(ssline, lanternType, '|');
			getline(ssline, lanternSize, '|');
			this->lanterns.push_back(Lantern(itemID, itemName, brand, itemType, dateOfPurchase, condition, status, fuelType, lanternType, lanternSize));
		}
		else if (itemID.substr(0, 1)[0] == 'S')
		{
			string fuelType;
			string stoveType;
			getline(ssline, fuelType, '|');
			getline(ssline, stoveType, '|');
			this->stoves.push_back(Stove(itemID, itemName, brand, itemType, dateOfPurchase, condition, status, fuelType, stoveType));

		}
	}

	updateEquipment();
}

void Initialization::insertRecord(std::string path)
{
	stringstream list = (stringstream)fileRead(path);
	string line;
	while (list && getline(list, line))
	{
		string loanDate, returnDate, equipId, userId, userName, equipName, status;
		stringstream ss(line);


		if ((ss.rdbuf()->in_avail()))
		{
			getline(ss, loanDate, '|');
			getline(ss, returnDate, '|');
			getline(ss, userId, '|');
			getline(ss, userName, '|');
			getline(ss, equipId, '|');
			getline(ss, equipName, '|');
			getline(ss, status, '|');

			this->records.push_back(LoanRecord(loanDate, returnDate, userId, userName, equipId, equipName, status));
		}
	}

}

void Initialization::addRecord(const LoanRecord & r)
{
	(this->records).push_back(r);

	string res;
	for (int i = 0; i < records.size(); i++) {
		res += records[i].getLoanRecord();
	}

	fileWrite("loan_record.txt", res);
}

User * Initialization::getUser() const
{
	User *ptr = NULL;

	if (this->index_of_user >= 0)
		ptr = this->users[this->index_of_user];

	return ptr;
}

std::vector<Tent> Initialization::getTents() const
{
	return tents;
}

std::vector<Stove> Initialization::getStoves() const
{
	return this->stoves;
}

std::vector<Lantern> Initialization::getLanterns() const
{
	return this->lanterns;
}

std::vector<LoanRecord> Initialization::getLoanRecord() const
{
	return this->records;
}

void Initialization::updateEquipment()
{
	string s = "";
	for (int i = 0; i < tents.size(); i++) {
		s += tents[i].getInfo();
	}

	for (int i = 0; i < stoves.size(); i++) {
		s += stoves[i].getInfo();
	}

	for (int i = 0; i < lanterns.size(); i++) {
		s += lanterns[i].getInfo();
	}

	fileWrite("camp_equipment.txt", s);
}

void Initialization::updateUser()
{
	string s = "";
	for (int i = 0; i < users.size(); i++)
		s += users[i]->getInfo();

	fileWrite("user.txt", s);
}



