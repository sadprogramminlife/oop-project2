#pragma once
#ifndef LOANRECORD_H
#define LOANRECORD_H

#include <time.h>
#include <string>
#include <sstream>

class LoanRecord 
{
private:
	std::string loanDate;
	std::string returnDate;
	std::string equipId;
	std::string userId;
	std::string userName;
	std::string equipName;
	bool status;		// 1 for returned, 0 for out for loan

	std::string newDate(int day);

public:
	LoanRecord(std::string loanDate, std::string returnDate, std::string equipId, std::string userId, std::string userName, std::string equipName);
	LoanRecord(std::string equipId, std::string userId, std::string userName, std::string equipName);

	std::string getLoanDate() const;
	std::string getReturnedDate() const;
	std::string getEquipId() const;
	std::string getUserId() const;
	std::string getUserName();
	std::string getEquipName() const;
	std::string getStatus() const;
	bool getBoolStatus() const;
	std::string getLoanRecord() const;

	LoanRecord returnEquipment() const;
};

#endif
