#pragma once
#ifndef LOANCONTROL_H
#define LOANCONTROL_H

#include "Initialization.h"
#include <type_traits>

class LoanControl : public Initialization
{
public:
	vector<LoanRecord> getUserLoanRecords();

	template <class E> 
	vector<E> getAvailableEquipments();

	bool performBorrowEquipment(string equipId);
	bool performReturnEquipment(string equipId);

};

#endif


