#pragma once
#include <stdlib.h>
#include <iostream>

#include <string>

// base class for the water/irrigation bill
class Basebill
{
public:
	Basebill(int AccountNumber, std::string CustomerName, int number);//base constructor function that initializes the account number, customer name and irrigaton number
	virtual ~Basebill(); // base destructor function that frees up the memory
	virtual double BasePrice() const; // base price for the water/irrigation bill
	virtual double CalculatePrice(); // base virtual function that calculates the irrigation/water bill
	virtual double GetCalculatedPrice(); // virtual function that returns the calculated price/bill
	void SetNumberWateringWeek(int number); // function that sets the number of times irrigation is done for the week
	int GetNumberWateringWeek(); //function that returns the number of times irrigation is done for the week
	virtual void SetTier(std::string data); // function that sets the Tier level attribute field
	virtual std::string GetTier();

private:
	int NumberWateringWeek = 1;	// attribute field that stores the number of times the irrigation is done in the week
	std::string Tier; // attribute field that stores the Tier level for the irrigation/water bill
};

