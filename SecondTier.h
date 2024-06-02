#pragma once
#include "Basebill.h"
#include <string> 

class SecondTier : public Basebill
{
public:
	SecondTier(int AccountNumber, std::string CustomerName, int number);//constructor function that initializes the account number, customer name and irrigaton number
	virtual double CalculatePrice();// function to calculate the water/irrigation bill per the number of times irrigation is done
	virtual void SetTier(std::string data); // void function that sets the Tier level for the water bill
	virtual std::string GetTier();// function that returns the Tier level for the weekly water bill based on how many times grass was watered
private:
	std::string Tier2; // attribute field that stores the number of times the irrigation is done in the week
};