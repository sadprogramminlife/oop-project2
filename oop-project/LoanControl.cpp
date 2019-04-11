#include "LoanControl.h"

template<typename E>
vector<E> LoanControl::getAvailableEquipments()
{
	vector<E> res;
	if (std::is_same<E, Tent>) {
		vector<E> tmp = tents;
	}
	else if (std::is_same<E, Stove>) {
		vector<E> tmp = stoves;
	}
	else if (std::is_same<E, Lantern>) {
		vector<E> tmp = lanterns;
	}

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].canBorrow())
			res.push_back(tmp[i]);
	}

	return res;
}