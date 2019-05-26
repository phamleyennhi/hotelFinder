#include "MapHotel.h"
#include <iostream>
//**************************
MapHotel::MapHotel(int capacity)
{
	hotelArr = new HashHotel*[capacity];
	this->capacity = capacity;
	this->size = 0;
	this->comparisons = 0;
}

//**************************
MapHotel::~MapHotel()
{
	delete[] this->hotelArr;
}
//**************************
const std::string MapHotel::returnKey(int hash){

	if(hotelArr[hash] != NULL)
		return hotelArr[hash]->getKey();
	else
		return "";
}
//**************************
Hotel MapHotel::returnValue(int hash){
	return hotelArr[hash]->getValue();
}
//**************************
int MapHotel::hash(const std::string key)
{
	long hashVal= 0;
	for(int i=0; i<key.length(); i++){
		// std::cout << "key[i]: " << key[i] << std::endl;
		if (key[i]*1 < 0) {
			hashVal += key[i]*(-1)*pow(i,5);
		}
		else hashVal += key[i]*pow(i,5); 		//Add ascci code of each letter times i power 5
	}
	return (hashVal)%capacity;	
}

//**************************
int MapHotel::insertHotel(const std::string key, const Hotel value){
	int id = hash(key)% capacity;

	if (hotelArr[id] == NULL){
		hotelArr[id] = new HashHotel(key, value);
	}
	else {
		while (hotelArr[id] != NULL){
			if(hotelArr[id]->getKey() == key){ //the data already exists
				return -1;
			}
			if(hotelArr[id]->getKey() == "T"){ //"T" is the delete marker
				hotelArr[id]->setValue(key, value);
				return 0;
			}
			id++;
			id = id%capacity;
		}
		hotelArr[id] = new HashHotel(key, value);
	}

	size++;
	return 0;
}

//**************************
Hotel MapHotel::searchHotel(const std::string key){
	int id = hash(key)%capacity;
	int start = id;
	int flag = 0;
	int cnt = 0;

	std::clock_t time1 = std::clock();


	if (hotelArr[id] != NULL && hotelArr[id]->getKey() == key){
		++cnt;
		return hotelArr[id]->getValue();
	}

	while (hotelArr[id] != NULL && hotelArr[id]->getKey() != key){
		++cnt;
		++id;
		id = id%capacity;
		if (id == start){ //if we already search through the whole array, stop.
			flag = -1;
			break;
		}
	}

	std::clock_t time2 = std::clock();
	lastTime = double(time2 - time1)  / CLOCKS_PER_SEC;

	comparisons = cnt;
	if (hotelArr[id] == NULL || flag == -1){ // we either reach the first empty slot or already scan through the whole array
		std::cout << "Not found" << std::endl;
		Hotel tmp = Hotel();
		return tmp;
	}
	else return hotelArr[id]->getValue();
}

//**************************
int MapHotel::deleteHotel(const std::string key){
	int id = hash(key)%capacity;
	int cnt = id;


	if (hotelArr[id] == NULL) {
		return -1;
	}


	while(hotelArr[id]!= NULL && hotelArr[id]->getKey() != key){
		id++;
		id = id%capacity;

		if (id == cnt){ // we already scan through the whole array and do not find the hotel
			return -1;
		}
	}

			

	if (hotelArr[id] != NULL ){

				

		hotelArr[id] = new HashHotel("T", hotelArr[id]->getValue()); // we use the marker "T" for deletion
		return 0;
	}

	return -1;
}
//************************
void MapHotel::lastComparisons(){
	std::cout<<"Comparisons performed: "<<comparisons<<"."<< std::endl;
	std::cout<<"Elapsed time: "<<std::fixed<<lastTime*1000000000<<" nanoseconds."<<std::endl;
	comparisons = 0;
	lastTime = 0;

}
