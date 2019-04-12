#include "LoanRecord.h"

std::string LoanRecord::newDate(int day = 0)
{
	// missing date

	return std::string();
}

LoanRecord::LoanRecord(std::string loanDate, std::string returnDate, std::string equipId, std::string userId, std::string userName, std::string equipName)
{
	this->loanDate = loanDate;
	this->returnDate = returnDate;
	this->equipId = equipId;
	this->userId = userId;
	this->userName = userName;
	this->equipName = equipName;

	this->status = false;		// out for loan
}

// connstructor for creating out for loan records
LoanRecord::LoanRecord(std::string userId, std::string userName, std::string equipId, std::string equipName)
{
	this->loanDate = "";		// change this later
	this->returnDate = "";			// change this later
	this->equipId = equipId;
	this->userId = userId;
	this->userName = userName;
	this->equipName = equipName;

	this->status = 0;
}

std::string LoanRecord::getLoanDate() const
{
	return this->loanDate;
}

std::string LoanRecord::getReturnedDate() const
{
	return this->returnDate;
}
 
std::string LoanRecord::getEquipId() const
{
	return this->equipId;
}

std::string LoanRecord::getUserId() const
{
	return this->userId;
}

std::string LoanRecord::getUserName() 
{
	return this->userName;
}

std::string LoanRecord::getEquipName() const
{
	return this->equipName;
}

std::string LoanRecord::getStatus() const
{
	return (this->status) ? "returned" : "out for loan";
}

bool LoanRecord::getBoolStatus() const
{
	return this->status;
}

std::string LoanRecord::getLoanRecord() const
{
	return std::string(this->loanDate + '|' + this->returnDate + '|' + this->userId + '|' + this->userName + '|' + this->equipId + '|' + this->equipName + '|' + this->getStatus() + '\n');
}

LoanRecord LoanRecord::returnEquipment() const
{
	LoanRecord tmp = *this;
	tmp.status = true;
	return tmp;
}
