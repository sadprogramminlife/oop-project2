#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Initialization.h"
#include "LoanControl.h"
#include "LoanRecord.h"
#include "Admin.h"
using namespace std;

void system();
void menu(int n, LoanControl *a);
void adminMenu(int n, Admin *a);

#endif
