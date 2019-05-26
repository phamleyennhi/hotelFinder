#ifndef HOTELFINDER
#define HOTELFINDER
#import <cstdlib>
#import <fstream>
#import <iostream>
#import <string>
#import <vector>
#import <algorithm>
#import <cmath>
#import <list>
#import <queue>
#import <sstream>
#import "MapCity.h"
#import "MapHotel.h"

class HotelFinder{
	private:
		MapHotel hotels;
		MapCity cities;
		int capacity;
	public:
		HotelFinder(int capacity);
		~HotelFinder();
		void readFile(const std::string filename);
		bool command(const std::string query);

		//Functions:
		void dump(const std::string filename);
		void cleanInput(std::string& value);
};
#endif
