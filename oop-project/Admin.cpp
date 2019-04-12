#include "Admin.h"

bool Admin::updateEquipCcondition(string eid, string condition)
{
	bool flag = !condition.compare("good") || !condition.compare("damaged")
		|| !condition.compare("being repaired") || !condition.compare("disposed");

	if (flag) {
		if (eid[0] == 'T') {
			for (int i = 0; i < tents.size(); i++) {
				if (eid.compare(tents[i].getItemID())) {
					tents[i].setCondition(condition);

					break;
				}
			}
		}
		else if (eid[1] == 'S') {
			for (int i = 0; i < stoves.size(); i++) {
				if (eid.compare(stoves[i].getItemID())) {
					stoves[i].setCondition(condition);

					break;
				}
			}

		}
		else if (eid[1] == 'L') {
			for (int i = 0; i < lanterns.size(); i++) {
				if (eid.compare(lanterns[i].getItemID())) {
					lanterns[i].setCondition(condition);

					break;
				}
			}
		}
	}

	return flag;
}
