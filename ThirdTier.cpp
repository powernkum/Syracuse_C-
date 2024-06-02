#include "ThirdTier.h"

// Constructor function that initializes the parameters accountnumber, customer name and number
ThirdTier::ThirdTier(int AccountNumber, std::string CustomerName, int number) :Basebill(AccountNumber, CustomerName, number)
{
	ThirdTier::SetTier("Tier3"); //calls the SetTier function and assigns/initializes the Tier3 level of the private data member Tier3
};


double ThirdTier::CalculatePrice()
{
	// return base price if the number of times the watering was done was less/equal 3
	if (ThirdTier::GetNumberWateringWeek() > 7 and ThirdTier::GetNumberWateringWeek() <= 9) {

		return ThirdTier::BasePrice() + 7 * 2.49;
	}

}

// function to set the string data and assign the data to the Tier3
void ThirdTier::SetTier(std::string data)
{
	Tier3 = data;
}
// function to receive the string data for the private field
std::string ThirdTier::GetTier()
{
	return Tier3;
}