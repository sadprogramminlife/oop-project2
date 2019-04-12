#include "User.h"

User::User(string id, string name, string section, string date, string address)
{
	this->id = id;
	this->name = name;
	this->section = section;
	this->date = date;
	this->address = address;

	this->borrownum = 0;
}

User::~User()
{
}

string User::getId() const
{
	return id;
}

string User::getName() const
{
	return name;
}

string User::getSection() const
{
	return section;
}

string User::getDob() const
{
	return date;
}

string User::getAddress() const
{
	return address;
}

string User::getUser() const
{
	return string(this->id + '|' + this->name + '|' + this->section + '|' + this->date + '|' + this->address);
}

string User::getInfo() const
{
	return string(getUser() + '\n');
}

bool User::borrowItem(string itemId)
{
	bool flag = false;
	if (borrownum < borrowlimit) {
		bool dup = false;
		for (int i = 0; i < itemList.size(); i++) {
			if (!itemList[i].compare(itemId)) {
				dup = true;

				break;
			}
		}

		if (!dup) {
			itemList.push_back(itemId);
			borrownum++;
			flag = true;
		}
	}

	return flag;
}

bool User::returnItem(string itemId)
{
	for (int i = 0; i < borrownum; i++) {
		if (!itemList[i].compare(itemId)) {
			itemList.erase(itemList.begin() + i);
			borrownum--;
			return true;
		}
	}

	return false;
}

bool User::canLoan()
{
	return (borrowlimit-borrownum);
}

/*
*/

void Scout::setItemLimit()
{
	int limit = -1;
	if (!(this->rank).compare("Member"))
		limit = 1;
	if (!(this->rank).compare("Patrol Leader") || !(this->rank).compare("Assistent Patrol Leader"))
		limit = 3;

	this->borrowlimit = limit;
}

string Scout::getRank()
{
	return this->rank;
}

string Scout::getInfo() const
{
	return string(getUser() + '|' + this->rank + '\n');
}

Scout::Scout(string id, string name, string section, string date, string address, string rank)
	: User::User(id, name, section, date, address)
{
	this->rank = rank;
	this->setItemLimit();
}

/*
*/

void VentureScout::setItemLimit()
{
	this->borrowlimit = 3;
}

string VentureScout::getInfo() const
{
	return string(getUser() + '\n');
}

VentureScout::VentureScout(string id, string name, string section, string date, string address)
	: User::User(id, name, section, date, address)
{
	this->setItemLimit();
}

/*
*/

void RoverScout::setItemLimit()
{
	this->borrowlimit = 5;
}

string RoverScout::getInfo() const
{
	return string(getUser() + '\n');
}

RoverScout::RoverScout(string id, string name, string section, string date, string address)
	: User::User(id, name, section, date, address)
{
	this->setItemLimit();
}

/*
*/

void Scouter::setItemLimit()
{
	this->borrowlimit = 5;
}

string Scouter::getRank()
{
	return this->rank;
}

string Scouter::getInfo() const
{
	return string(getUser() + '|' + this->rank + '\n');
}

Scouter::Scouter(string id, string name, string section, string date, string address, string rank)
	: User::User(id, name, section, date, address)
{
	this->rank = rank;
	this->setItemLimit();
}
