#include "Initialization.h"



Initialization::Initialization()
{
}


Initialization::~Initialization()
{
}

Initialization::Initialization(std::string username, std::string password, bool isAdmin, bool isUser)
{
	insertUser();

	isAdmin = false;
	isUser = false;

	if ( username.compare("admin") || password.compare("admin") ) {			// return 1 if user is not admin
		this->index_of_user = -1;
		isAdmin = true;
	}
	else {
		for (int i = 0; i < users.size(); i++) {
			if (username.compare(users[0]->getId) || password.compare(users[0]->getDob)) {
				isUser = true;
			}
		}
	}

	if (isAdmin ^ isUser) {
		insertEquip();
		insertRecord();
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

		if (ss.peek() != '\n')
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
				this->users.push_back(new VentureScout(id, name, date, section, address));
			}
			else if (id.substr(0, 3) == "ROV")
			{
				this->users.push_back(new RoverScout(id, name, date, section, address));
			}
			else if (id.substr(0, 3) == "SCT")
			{
				this->users.push_back(new Scout(id, name, date, section, address, rank));
			}
			else if (id.substr(0, 3) == "SCM")
			{
				this->users.push_back(new Scouter(id, name, date, section, address, rank));
			}
		}
	}
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
		else
		{
			if (itemID.substr(0, 1)[0] == 'L')
			{
				string fuelType;
				string lanternType;
				string lanternSize;
				getline(ssline, fuelType, '|');
				getline(ssline, lanternType, '|');
				getline(ssline, lanternSize, '|');
				this->lanterns.push_back(Lantern(itemID, itemName, brand, itemType, dateOfPurchase, condition, status, fuelType, lanternType, lanternSize));
			}
			else
			{
				string fuelType;
				string stoveType;
				getline(ssline, fuelType, '|');
				getline(ssline, stoveType, '|');
				this->stoves.push_back(Stove(itemID, itemName, brand, itemType, dateOfPurchase, condition, status, fuelType, stoveType));
			}
		}
	}
}

void Initialization::insertRecord(std::string path)
{

}
