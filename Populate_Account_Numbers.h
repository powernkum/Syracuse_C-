#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Basebill.h"

class PopulateAccountNumbers
{
public:

	PopulateAccountNumbers(); // initialize the constructor

	// destructor function 
	~PopulateAccountNumbers();

	std::vector<int>GetAccounts();// function to get the account numbers
	std::vector<std::string>GetNames(); // function to get the names in respect to the accounts


private:
	std::vector<int>Accounts;
	std::vector<std::string>Names;
	
};
