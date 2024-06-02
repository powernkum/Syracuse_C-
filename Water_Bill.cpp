//Michael Preko Nkum
//CIS 554-M401 Object Oriented Programming in C++
//Syracuse University
//Final Project
//03/23/2023
//This project basically calculates the water bill in tiers

#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Basebill.h"
#include "FirstTier.h"
#include "SecondTier.h"
#include "ThirdTier.h"
#include "Populate_Account_Numbers.h"
#include <iomanip>
#include <typeinfo>
#include <cmath>




bool validNumber(std::string& str); // boolean function that checks validity of input data
std::string UpperCase(std::string stringvalue); // string function that converts lower case string into an upper case string

int main()
{
	//Banner
	std::cout << "      *********************************************************************************" << std::endl;
	std::cout << "      **                    Final Project : Water Bill                               **" << std::endl;
	std::cout << "      **                    Name          : Michael Preko Nkum                       **" << std::endl;
	std::cout << "      *********************************************************************************" << std::endl << std::endl;

	std::cout << "      ---------------------------------------------------------------------------------" << std::endl;
	std::cout << "                             Welcome to the Water Bill Tier program"                     << std::endl;
	std::cout << "      ---------------------------------------------------------------------------------" << std::endl << std::endl;

	int AccountNumber1{0}; // initializes the account number
	int Numb_watered{0}; // initializes the number of times grass is watered
	std::string Name = ""; // initializes the Name string
	bool validation1 = false; //initializes the boolean validation 
	bool validation2 = false;  //initializes the boolean validation 

	// reads the accounts text file on the C-drive and populate sthe accounts and number vector by calling the default constructor
	PopulateAccountNumbers Populate; // creates an instance of the Populate Class and populates vector of accounts and names with the text file

	//ask the user to enter the account number and query it out from the account vector
	std::cout << "Enter your account number (or -1 to quit): ";
	std::cin >> AccountNumber1;

	//cin.fail() returns true if the last cin command failed, and false otherwise.
	while (std::cin.fail())
	{
		std::cout << "\nPlease enter an integer for the account number\n";
		// clear error state/error flag on cin
		std::cin.clear();
		// discard 'bad' character(s)
		// ignore the rest of the current line until \n or EOF, whichever comes first
		// set the maximum number of characters to ignore
		// since this is the upper limit on the size of a stream, you're effectively telling
		// cin that there is no limit to the number of characters to ignore
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your account number (or -1 to quit): ";
		std::cin >> AccountNumber1;// read in account number
	}

	// set floating-point number format
	std::cout << std::fixed << std::setprecision(2);

	while (AccountNumber1 != -1) {
		
		//Query the vector to extract/validate the account number - retry again in case the account number is not found
			// name of account vector is Populate::GetAccounts() ***
			// loop through to validate the account number in the vector
		for (int loop = 0; loop < Populate.GetAccounts().size(); loop++)
		{
			if (AccountNumber1 == Populate.GetAccounts().at(loop))
			{ 
				validation1 = true; //assigns validation to be true as queried account number exists in the text file
			}

		}

		//ask the user to enter his/her first name and query it out from the names vector
		std::cout << "Enter your first name : ";
		std::cin >> Name;

		while (validNumber(Name) == false)
		{
			//ask the user to enter his/her name for validation
			std::cout << "Enter a valid first name :";
			std::cin.ignore();
			std::cin >> Name;
		}
		// calling the uppercase function to convert the string value into an upper case
		Name = UpperCase(Name);
			//Query the vector to extract/validate the name number - retry again in case the account number is not found
			// loop through to validate the account name in the vector
			for (int loop = 0; loop < Populate.GetNames().size(); loop++)
				//for (auto &row:myArray)
			{
				if (Name == Populate.GetNames().at(loop))
				{
					validation2 = true; //assigns validation to be true as queried account number exists in the text file

				}

			}
		//ask the user to enter the number of times the grass was watered
		std::cout << "Enter the number of times grass was watered " << " (-1 to end) : ";
		std::cin >> Numb_watered;

		while (std::cin.fail())
		{
			std::cout << "\nPlease enter a valid integer for the duration\n";
			// clear error state
			std::cin.clear();
			// discard 'bad' character(s)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter the number of times grass was watered (or -1 to quit): ";
			std::cin >> Numb_watered;
		}
			if (validation1 == true && validation2 == true) {
				std::vector <Basebill*> Basebill2(4);

				// initialize vector with Bill
				Basebill2[0] = new Basebill(AccountNumber1, Name, Numb_watered);
				Basebill2[1] = new FirstTier(AccountNumber1, Name, Numb_watered);
				Basebill2[2] = new SecondTier(AccountNumber1, Name, Numb_watered);
				Basebill2[3] = new ThirdTier(AccountNumber1, Name, Numb_watered);

				// set floating-point output formatting
				std::cout << std::fixed << std::setprecision(2);

				// generically process each element in vector tiers based on the return value of the bill
				for (int i = 0; i < Basebill2.size(); i++) {
					int Value = signbit(static_cast<double>(Basebill2[i]->CalculatePrice())); // determines the sign of the bill calculated
					if (Basebill2[i]->CalculatePrice() != 0.0 && Value !=1){ // ignores any overflow and also ignores bills that are zer0
						std::cout << "Account Number "<< AccountNumber1 <<" has a "<< Basebill2[i]->GetTier() <<" Bill of $" << Basebill2[i]->CalculatePrice() << std::endl;
					}
				}

				// release memory held by vector employees
				for (int j = 0; j < Basebill2.size(); j++) {

					// output class name 
					//std::cout << "\ndeleting object of "<< typeid(*Basebill2[j]).name();
					delete Basebill2[j]; // deletes the objects created from the base pointers

				} // end for

				std::cout << std::endl;

				//ask the user to enter the account number and query it out from the account vector
				std::cout << "\nEnter your account number (or -1 to quit): ";
				std::cin >> AccountNumber1;

				// re-initialize the validation
				validation1 = false; 
				validation2 = false;

				//cin.fail() returns true if the last cin command failed, and false otherwise.
				while (std::cin.fail())
				{
					std::cout << "\nPlease enter an integer for the account number\n";
					// clear error state/error flag on cin
					std::cin.clear();
					// discard 'bad' character(s)
					// ignore the rest of the current line until \n or EOF, whichever comes first
					// set the maximum number of characters to ignore
					// since this is the upper limit on the size of a stream, you're effectively telling
					// cin that there is no limit to the number of characters to ignore
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Enter your account number (or -1 to quit): ";
					std::cin >> AccountNumber1;// read in account number
					
				}

			}
			else {

				std::cout << "\nThe account number or account name entered is not found in the list so please re-enter the details\n";

				//ask the user to enter the account number and query it out from the account vector
				std::cout << "Enter your account number (or -1 to quit): ";
				std::cin >> AccountNumber1;

				// re-initialize the validation
				validation1 = false;
				validation2 = false;

				//cin.fail() returns true if the last cin command failed, and false otherwise.
				while (std::cin.fail())
				{
					std::cout << "\nPlease enter an integer for the account number\n";
					// clear error state/error flag on cin
					std::cin.clear();
					// discard 'bad' character(s)
					// ignore the rest of the current line until \n or EOF, whichever comes first
					// set the maximum number of characters to ignore
					// since this is the upper limit on the size of a stream, you're effectively telling
					// cin that there is no limit to the number of characters to ignore
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Enter your account number (or -1 to quit): ";
					std::cin >> AccountNumber1;// read in account number
				}
			}
	}
}

// boolean function to check the validity of the input string
bool validNumber(std::string& str)
{
	
	// verify if the number entry is a number and not a character
	for (char const& c : str)
	{
		if (isdigit(c) != 0)
			return false;
	}
	return true;
	
}

// function that converts a string of lower case into a string of upper case
std::string UpperCase(std::string stringvalue)
{
	//convert the string to uppercase
	std::string sub = "";
	char ch;
	for (int i = 0; i < size(stringvalue); i++)
	{
		sub = sub + std::string(1, toupper(stringvalue[i]));
	}
	return sub;
}