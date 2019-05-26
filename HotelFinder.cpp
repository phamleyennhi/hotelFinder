#include "HotelFinder.h"
#include <iostream>
#include <queue>

bool operator<(const Hotel& h1, const Hotel& h2) 
{ 
    return h1.hotelName > h2.hotelName; 
} 

bool operator>(const Hotel& h1, const Hotel& h2) 
{ 
    return h1.hotelName < h2.hotelName; 
} 
//**************************
HotelFinder::HotelFinder(int capacity): hotels(capacity), cities(capacity){
	this->capacity = capacity;
}
//**************************
HotelFinder::~HotelFinder(){}
//**************************
void HotelFinder::readFile(const std::string filename){

	std::ifstream fin;
	fin.open(filename);



	if (!fin.fail()){

		std::string line;
		getline(fin,line); //skip first line

		while (!fin.eof()){
			std::string hotelName, cityName, stars, price, countryName, address;
			getline(fin,hotelName,',');
			getline(fin,cityName,',');
			getline(fin,stars,',');
			getline(fin,price,',');
			getline(fin,countryName,',');
			getline(fin, address);
			//std::cout << "Hotel: " << hotelName << "," << cityName << std::endl;
			hotels.insertHotel(hotelName+","+cityName, Hotel(hotelName, cityName, stod(stars), stod(price), countryName, address));
			cities.insertHotel(cityName, Hotel(hotelName, cityName, stod(stars), stod(price), countryName, address));

		}
	}

	fin.close();
}
//**************************
bool HotelFinder::command(const std::string query){

	if(query == "find"){
		std::string hotelName, cityName;
		getline(std::cin,hotelName,',');
		getline(std::cin,cityName);
		cleanInput(hotelName);
		cleanInput(cityName);
		Hotel out = hotels.searchHotel(hotelName+","+cityName);
		out.printHotel();
		hotels.lastComparisons();

		return true;

	}else if(query == "add"){

		std::string hotelName, cityName, stars, price, countryName, address;
		getline(std::cin,hotelName,',');
		getline(std::cin,cityName,',');
		getline(std::cin,stars,',');
		getline(std::cin,price,',');
		getline(std::cin,countryName,',');
		getline(std::cin, address);
		cleanInput(hotelName);
		cleanInput(cityName);
		cleanInput(stars);
		cleanInput(price);
		cleanInput(countryName);
		cleanInput(address);

		//the flagCheck if the data exist to be deleted. If flagCheck = 0. yes. Else if flagCheck = -1, no.
		int flagCheck = hotels.insertHotel(hotelName+","+cityName, Hotel(hotelName, cityName, stod(stars), stod(price), countryName, address));
		cities.insertHotel(cityName, Hotel(hotelName, cityName, stod(stars), stod(price), countryName, address));
		if (flagCheck == 0)
			std::cout<<"Data saved."<< std::endl;
		else std::cout << "Data already exists. Please input another data...!" << std::endl;
		return true;

	}else if(query == "delete"){
		std::string hotelName, cityName;
		getline(std::cin,hotelName,',');
		getline(std::cin,cityName);
		cleanInput(hotelName);
		cleanInput(cityName);

		hotels.deleteHotel(hotelName+","+cityName);
		int flagCheck = cities.deleteHotel(cityName, hotelName);
		if (flagCheck == 0){
			std::cout<<"Data deleted."<< std::endl;
		}
		else std::cout<<"Data does not exist."<< std::endl;
		return true;

	}else if(query == "dump"){

		std::priority_queue<Hotel> Q;

		for (int i = 0; i < capacity; ++i)
		{
			if(hotels.returnKey(i) != ""){
			 	if(hotels.returnKey(i) != "T"){ //because when we delete, we use marker T.
					Q.push(hotels.returnValue(i));
				}
			}
		}

		//Save to file
		std::string outputfile;
		getline(std::cin, outputfile);
		cleanInput(outputfile);

		std::ofstream fout;
		fout.open(outputfile);

		if (fout.is_open()){

			while(!Q.empty()){
				fout << Q.top().hotelLabel()<<'\n';
				Q.pop();
			}
			fout.close();
		}

		std::cout<<"Data saved to "<<outputfile<< std::endl;

		return true;

	}else if(query == "allinCity"){
		std::string city;
		getline(std::cin,city);
		cleanInput(city);
		cities.searchCity(city);

		return true;

	}else if(query == "quit"){

		std::cout<<"Quitting the program..."<< std::endl;
		return false;

	}else{

		std::cout<<"Command not found..."<< std::endl;
		std::cout<<"Possible commands: find, add, delete, dump, allinCity, quit"<< std::endl;
	}

	return true;
}


void HotelFinder::cleanInput(std::string& value)
{
	char whitespace[5] = {' ', '\t'};
	value.erase(0, value.find_first_not_of(whitespace));
	value.erase(value.find_last_not_of(whitespace) + 1);
}

