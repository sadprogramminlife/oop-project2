#pragma once
#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <vector>
#include <iostream>		// delete after the debug
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

	void insertUser(std::string path = "user.txt");
	void insertEquip(std::string path = "camp_equipment.txt");
	void insertRecord(std::string path = "loan_record.txt");

public:

	Initialization();
	Initialization(std::string username, std::string password, bool &isAdmin, bool &isSuccess);

	~Initialization();

	User *getUser() const;
	std::vector<Tent> getTents() const;
	std::vector<Stove> getStoves() const;
	std::vector<Lantern> getLanterns() const;
	std::vector<LoanRecord> getLoanRecord() const; 

};

#endif

