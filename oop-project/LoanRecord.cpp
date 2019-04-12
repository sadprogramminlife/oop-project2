#include "LoanRecord.h"

std::string LoanRecord::newDate(int days)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	std::stringstream ss;
	ss << (now->tm_mday + days)
		<< (now->tm_mon + 1)
		<< (now->tm_year + 1900);

	return ss.str();
}

LoanRecord::LoanRecord(std::string loanDate, std::string returnDate, std::string userId, std::string userName, std::string equipId, std::string equipName, std::string sstatus)
{
	this->loanDate = loanDate;
	this->returnDate = returnDate;
	this->equipId = equipId;
	this->userId = userId;
	this->userName = userName;
	this->equipName = equipName;

	this->status = (!sstatus.compare("out for loan"))?0:1;
}

// connstructor for creating out for loan records
LoanRecord::LoanRecord(std::string userId, std::string userName, std::string equipId, std::string equipName)
{
	this->loanDate = newDate();		// change this later
	this->returnDate = newDate(14);			// change this later
	this->userId = userId;
	this->userName = userName;
	this->equipId = equipId;
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
