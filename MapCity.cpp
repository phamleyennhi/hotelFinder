#include "MapCity.h"
#include <iostream>
#include <list>

//****************************
MapCity::MapCity(int capacity)
{
	buckets = new std::list<HashHotel>[capacity];
	this->capacity = capacity;
	this->size = 0;
}

//****************************
MapCity::~MapCity(){
	delete[] this->buckets;
}

//**************************
int MapCity::hash(const std::string key){
	long hashVal=0;
	for(int i=0; i<key.length(); i++){
		if (key[i]*1 < 0) { //deal with special characters that have negative ascci code.
			hashVal += (key[i]*(-1))*pow(i,5);
		}
		else hashVal += key[i]*pow(i,5); 		//Add ascci code of each letter times i power 5
	}
	return (hashVal)%capacity;	
}

//**************************
void MapCity::insertHotel(const std::string key, const Hotel value){
	int id = hash(key)%capacity;
	buckets[id].push_back(HashHotel(key, value));
	if (buckets[id].size() == 0) size++;
}

//**************************
int MapCity::deleteHotel(const std::string key, const std::string hotelName){
	int id = hash(key)%capacity;
	if (buckets[id].size() == 0) {
		return -1;
	}
	//we go through the list to find the hotel we need to delete
	else {
		for (std::list<HashHotel>::iterator it=buckets[id].begin(); it != buckets[id].end(); ++it){
			if (it->getKey() == key){
				if(it->getValue().getName() == hotelName){
					buckets[id].erase(it);
					return 0;
				}
			}
		}
	}
	return -1;
}

//**************************
void MapCity::searchCity(const std::string key){
	long id = hash(key)%capacity;
	if (buckets[id].size() == 0){
		std::cout << "Record not found...!" << std::endl;
	}
	//we go through the list to find the hotel.
	else {
		for (std::list<HashHotel>::iterator it=buckets[id].begin(); it != buckets[id].end(); ++it){
			if (it->getKey() == key){
				it->getValue().printHotel();
			}
		}
	}
}