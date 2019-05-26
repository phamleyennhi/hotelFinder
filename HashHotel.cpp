#include "HashHotel.h"

//**************************
HashHotel::HashHotel(std::string key, Hotel value){
	this->key = key;
	this->value = value;
}

//**************************
std::string HashHotel::getKey(){
	return this->key;
}

//**************************
Hotel HashHotel::getValue(){
	return this->value;
}

//**************************
void HashHotel::setValue(std::string key, Hotel value){
	this->value = value;
	this->key = key;
}