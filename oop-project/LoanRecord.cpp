#include "LoanRecord.h"

LoanRecord::LoanRecord(std::string equipId, std::string userId, std::string userName, std::string equipName)
{
	this->equipId = equipId;
	this->userId = userId;
	this->userName = userName;
	this->equipName = equipName;
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
	this->equipId;
}

std::string LoanRecord::getUserId() const
{
	this->userId;
}

std::string LoanRecord::getUserName() const
{
	this->userName;
}

std::string LoanRecord::getEquipName() const
{
	this->equipName;
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
	return std::string(this->loanDate + '|' + this->returnDate + '|' + this->equipId + '|' + this->userId + '|' + this->userName + '|' + this->equipName);
}
