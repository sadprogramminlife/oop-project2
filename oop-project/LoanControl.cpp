#include "LoanControl.h"

vector<Tent> LoanControl::getAvailableTents() const
{
	vector<Tent> tmp = this->getTents();
	return filter(tmp);
}

vector<Stove> LoanControl::getAvailableStoves() const
{
	vector<Stove> tmp = this->getStoves();
	return filter(tmp);
}

vector<Lantern> LoanControl::getAvailableLanterns() const
{
	vector<Lantern> tmp = this->getLanterns();
	return filter(tmp);
}

LoanControl::LoanControl()
{
	this->getUserLoanRecords();
}

vector<LoanRecord> LoanControl::getUserLoanRecords() const
{
	int size = (this->getLoanRecord()).size();
	vector<LoanRecord> *r = &(this->getLoanRecord());
	vector<LoanRecord> res;

	for (int i = 0; i < size; i++) {

		LoanRecord r = this->getLoanRecord()[i];
		if (!r.getBoolStatus() && !r.getUserId().compare(this->getUser()->getId())) {
			bool flag = true;
			string match_eid = r.getEquipId();

			for (int j = i+1; flag && j < size; j++) {
				bool checkName = !this->getLoanRecord()[j].getUserId().compare(getUser()->getId());
				bool checkEID = !this->getLoanRecord()[j].getEquipId().compare(match_eid);
				bool checkStatus = this->getLoanRecord()[j].getBoolStatus();
				if (checkName && checkEID && checkStatus) {
					flag = false;
				}
			}

			if (flag) {
				res.push_back(r);
				this->getUser()->borrowItem(r.getEquipId());
			}
		}
	}

	return res;
}

template<class E>
E LoanControl::filter(E tmp) const
{
	E res;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].canBorrow())
			res.push_back(tmp[i]);
	}

	return res;
}

bool LoanControl::performBorrowEquipment(string equipId, vector<Tent> &equipment)
{
	bool flag = false;
	if (this->getUser()->canLoan()) {

		for (int i = 0; i < equipment.size(); i++) {
			if (!equipment[i].getItemID().compare(equipId)) {
				if (equipment[i].canBorrow() && this->getUser()->borrowItem(equipId)) {
					tents[i].setStatus("out");

					updateEquipment();
					addRecord(LoanRecord(this->getUser()->getId(), this->getUser()->getName(),
						equipment[i].getItemID(), equipment[i].getItemName()));

					flag = true;
				}
				else {
					break;
				}
			}
		}
	}

	return flag;
}
bool LoanControl::performBorrowEquipment(string equipId, vector<Stove> &equipment)
{
	bool flag = false;
	if (this->getUser()->canLoan()) {

		for (int i = 0; i < equipment.size(); i++) {
			if (!equipment[i].getItemID().compare(equipId)) {
				if (equipment[i].canBorrow() && this->getUser()->borrowItem(equipId)) {
					stoves[i].setStatus("out");

					updateEquipment();
					addRecord(LoanRecord(this->getUser()->getId(), this->getUser()->getName(),
						equipment[i].getItemID(), equipment[i].getItemName()));

					flag = true;
				}
				else {
					break;
				}
			}
		}
	}

	return flag;
}
bool LoanControl::performBorrowEquipment(string equipId, vector<Lantern> &equipment)
{
	bool flag = false;
	if (this->getUser()->canLoan()) {

		for (int i = 0; i < equipment.size(); i++) {
			if (!equipment[i].getItemID().compare(equipId)) {
				if (equipment[i].canBorrow() && this->getUser()->borrowItem(equipId)) {
					lanterns[i].setStatus("out");

					updateEquipment();
					addRecord(LoanRecord(this->getUser()->getId(), this->getUser()->getName(),
						equipment[i].getItemID(), equipment[i].getItemName()));

					flag = true;
				}
				else {
					break;
				}
			}
		}
	}

	return flag;
}

bool LoanControl::performReturnEquipment(string equipId, vector<Tent>& equipment)
{
	bool flag = false;
	for (int i = 0; !flag && i < equipment.size(); i++) {
		if (!equipId.compare(equipment[i].getItemID())) {
			User *user = getUser();
			if (user->returnItem(equipId)) {
				int j;
				bool s = 1;
				for (j = 0; j < records.size(); j++) {
					if (!records[j].getUserId().compare(user->getId()) && !records[j].getEquipId().compare(equipId)) {
						s = records[j].getBoolStatus();		// 0 for out for loean and 1 for returned

						break;
					}
				}

				if (!s) {
					equipment[j].setStatus("in");
					addRecord(records[j].returnEquipment());
					updateEquipment();

					flag = true;
				}
			}
		}
	}

	return flag;
}
bool LoanControl::performReturnEquipment(string equipId, vector<Stove>& equipment)
{
	bool flag = false;
	for (int i = 0; !flag && i < equipment.size(); i++) {
		if (!equipId.compare(equipment[i].getItemID())) {
			User *user = getUser();
			if (user->returnItem(equipId)) {
				int j;
				bool s = 1;
				for (j = 0; j < records.size(); j++) {
					if (!records[j].getUserId().compare(user->getId()) && !records[j].getEquipId().compare(equipId)) {
						s = records[j].getBoolStatus();		// 0 for out for loean and 1 for returned

						break;
					}
				}

				if (!s) {
					equipment[j].setStatus("in");
					addRecord(records[j].returnEquipment());
					updateEquipment();

					flag = true;
				}
			}
		}
	}

	return flag;
}
bool LoanControl::performReturnEquipment(string equipId, vector<Lantern>& equipment)
{
	bool flag = false;
	for (int i = 0; !flag && i < equipment.size(); i++) {
		if (!equipId.compare(equipment[i].getItemID())) {
			User *user = getUser();
			if (user->returnItem(equipId)) {
				int j;
				bool s = 1;
				for (j = 0; j < records.size(); j++) {
					if (!records[j].getUserId().compare(user->getId()) && !records[j].getEquipId().compare(equipId)) {
						s = records[j].getBoolStatus();		// 0 for out for loean and 1 for returned

						break;
					}
				}

				if (!s) {
					equipment[j].setStatus("in");
					addRecord(records[j].returnEquipment());
					updateEquipment();

					flag = true;
				}
			}
		}
	}

	return flag;
}