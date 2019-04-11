#include <iostream>
#include <string>
#include <vector>
#include "Initialization.h"

using namespace std;

int main() {
	bool isAdmin, isUser;
	std::string a = "VEN001";
	std::string b = "13041990";
	Initialization i(a, b, isAdmin, isUser);
	i.getLanterns();


}