#pragma once
#ifndef LOANCONTROL_H
#define LOANCONTROL_H

#include "Initialization.h"

class LoanControl : public Initialization
{
public:

	LoanControl();
	vector<LoanRecord> getUserLoanRecords() const;

	template <class E>
	E filter(E tmp) const;

	vector<Tent>  getAvailableTents() const;
	vector<Stove> getAvailableStoves() const;
	vector<Lantern> getAvailableLanterns() const;

	bool performBorrowEquipment(string equipId, vector<Tent> &equipment);
	bool performBorrowEquipment(string equipId, vector<Stove> &equipment);
	bool performBorrowEquipment(string equipId, vector<Lantern> &equipment);

	bool performReturnEquipment(string equipId, vector<Tent> &equipment);
	bool performReturnEquipment(string equipId, vector<Stove> &equipment);
	bool performReturnEquipment(string equipId, vector<Lantern> &equipment);

};

#endif


