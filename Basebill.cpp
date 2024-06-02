#include "Basebill.h"

// Base Constructor function that initializes the parameters accountnumber, customer name and number
Basebill::Basebill(int AccountNumber, std::string CustomerName, int number) :NumberWateringWeek{number}{
	Basebill::SetTier("Tier"); // calls the SetTier function and assigns the Tier1 to the private data member Tier1
}
// Destructor whcih frees up the memory
Basebill::~Basebill()
{}

// function that returns the base bill
double Basebill::BasePrice() const
{
	return 20.84; // Water Base Facility Charge
}

// function that calculates the bill for the week based on the number of times the irrigation is done
double Basebill::CalculatePrice()
{
	// return base price if the number of times the watering was done was less/equal 3
	if (Basebill::GetNumberWateringWeek() <= 3) {

		return Basebill::BasePrice();
	}
}

// function that returns the Calculated bill
double Basebill::GetCalculatedPrice()
{
	return 0.0;
}

// function that sets the number of times the irrigation is carried out per week
void Basebill::SetNumberWateringWeek(int number)
{
	NumberWateringWeek = number;
}

// function that returns the number of times the irrigation is done
int Basebill::GetNumberWateringWeek()
{
	return NumberWateringWeek;
}

// function to set the string data and assign the data to the Tier1
void Basebill::SetTier(std::string data)
{
	Tier = data;
}
// function to receive the string data for the private field
std::string Basebill::GetTier()
{
	return Tier;
}
