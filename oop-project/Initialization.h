#pragma once
#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <vector>
#include "User.h"
#include "Equipment.h"
#include "LoanRecord.h"
#include "FileHandler.h"

class Initialization
{

private:
	int index_of_user;

	std::vector<User*> users;
	std::vector<Tent> tents;
	std::vector<Stove> stoves;
	std::vector<Lantern> lanterns;
	std::vector<LoanRecord> records;

protected:

	Initialization();
	Initialization(std::string username, std::string password, bool isAdmin, bool isSuccess);

	void insertUser(std::string path = "user.txt");
	void insertEquip(std::string path = "camp_equipment.txt");
	void insertRecord(std::string path = "loan_record.txt");

public:
	std::vector<User> getUsers() const;
	std::vector<Equipment> getEquiment() const;
	std::vector<LoanRecord> getLoanRecord() const; 

};

#endif

