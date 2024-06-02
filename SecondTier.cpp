#include "SecondTier.h"

// Constructor function that initializes the parameters accountnumber, customer name and number
SecondTier::SecondTier(int AccountNumber, std::string CustomerName, int number) :Basebill(AccountNumber, CustomerName, number)
{
	SecondTier::SetTier("Tier2"); //calls the SetTier function and assigns/initializes the Tier2 level of the private data member Tier2
};

double SecondTier::CalculatePrice()
{
	
	// return base price if the number of times the watering was done was less/equal 3
	if (SecondTier::GetNumberWateringWeek() > 5 and SecondTier::GetNumberWateringWeek() <= 7) {
		return SecondTier::BasePrice() + 5 * 2.76;
	}
}
// function to set the string data and assign the data to the Tier2
void SecondTier::SetTier(std::string data)
{
	Tier2 = data;
}
// function to receive the string data for the private field
std::string SecondTier::GetTier()
{
	return Tier2;
}