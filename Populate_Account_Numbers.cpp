#pragma once
#include <stdlib.h>
#include <iostream>
#include "Populate_Account_Numbers.h"
#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include "Basebill.h"

//Read the account numbers and names from the text file and populate them in the Accounts and Names vector
PopulateAccountNumbers::PopulateAccountNumbers()
{
	// Open the text file and populate the Accounts and Names vectors with the account numbers and names
	std::ifstream ifs;
	ifs.open("C:\\Accounts.txt");
	if (ifs.fail()) {
		std::cerr << "Error opening a file" << std::endl;
		ifs.close();
		exit(1);
	}
	if (ifs.is_open()) {
		int number;
		std::string str;
		char c;
		while (ifs >> number >> c >> str && c == ','){
		Accounts.push_back(number); // populate the accounts vector with the account number from the text file
		Names.push_back(str); //populate the names vector with the names in respect to each account from the text file
		}
	}
	ifs.close();
}


PopulateAccountNumbers::~PopulateAccountNumbers()
{
}
// function that returns a vector containing the account numbers
std::vector<int> PopulateAccountNumbers::GetAccounts()
{
	return Accounts;
}
// function that returns a vector containing the first name associated with account
std::vector<std::string> PopulateAccountNumbers::GetNames()
{
	return Names;
}

