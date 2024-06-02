#include "FirstTier.h"

// Constructor function that initializes the parameters accountnumber, customer name and number
FirstTier::FirstTier(int AccountNumber, std::string CustomerName, int number):Basebill(AccountNumber,CustomerName,number)
{
	FirstTier::SetTier("Tier1");// calls the SetTier function and assigns/initializes the Tier1 level of the private data member Tier1

};

double FirstTier::CalculatePrice()
{
	
	// return base price if the number of times the watering was done was less/equal 3
	if (FirstTier::GetNumberWateringWeek() > 3 and FirstTier::GetNumberWateringWeek() <=5) {
		return FirstTier::BasePrice() + 3*3.99;
	}
}
// function to set the string data and assign the data to the Tier1
void FirstTier::SetTier(std::string data)
{	
	Tier1 = data;
}
// function to receive the string data for the private field
std::string FirstTier::GetTier()
{
	return Tier1;
}

