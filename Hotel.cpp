#include "Hotel.h"
#include <iostream>
//**************************
Hotel::Hotel(){
	this->hotelName = "";
	this->cityName = "";
	this->stars = 0.0;
	this->price = 0.0;
	this->countryName = "";
	this->address = "";
}

//**************************
Hotel::Hotel(std::string hotelName, std::string cityName, double stars, double price, std::string countryName, std::string address)
{
	this->hotelName = hotelName;
	this->cityName = cityName;
	this->stars = stars;
	this->price = price;
	this->countryName = countryName;
	this->address = address;
}
//**************************
const std::string Hotel::getName()
{
	return this->hotelName;
}
//**************************
void Hotel::printHotel()
{
	if(hotelName!="")
		std::cout << hotelName << "," << cityName << "," << stars << "," << price << "," << countryName << "," << address << std::endl;
}
//**************************
const std::string Hotel::hotelLabel() const {
	return hotelName+", "+cityName+", "+ std::to_string(stars)+", "+ std::to_string(price)+", "+countryName+", "+address;
}

//**************************
//Overload operator != to compare 2 objects of type Hotel
bool Hotel:: operator != (const Hotel value){
	if (this->hotelName != value.hotelName || this->cityName != value.cityName || this->stars != value.stars || this->price != value.price || this->countryName != value.countryName || this->address != value.address)
		return true;
	else return false;
}
