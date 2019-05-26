#ifndef MAPCITY
#define MAPCITY
#import <string>
#import "HashHotel.h"
#import <list>
#import <algorithm>
#import <cmath>
#import "Hotel.h"

class MapCity{
	private:
		std::list<HashHotel> *buckets;
		int size;
		int capacity;
	public:
		MapCity(int capacity);
		~MapCity();
		int hash(const std::string key);
		void insertHotel(const std::string key, const Hotel value);
		int deleteHotel(const std::string key, const std::string hotelName);
		void searchCity(const std::string key);
};
#endif
