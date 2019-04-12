#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "Initialization.h"

class Admin : public Initialization
{
public:
	bool updateEquipCcondition(string eid, string condition);
};

#endif