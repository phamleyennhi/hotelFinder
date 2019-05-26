#ifndef MAPHOTEL
#define MAPHOTEL
#import<string>
#import "HashHotel.h"
#import<list>
#import<algorithm>
#import<cmath>
#include <ctime>
#import "Hotel.h"

class MapHotel{
	private:
		HashHotel **hotelArr;
		int size;
		int capacity;
		int comparisons;	//number of comparisons performed by the last search
		double lastTime;

	public:
		MapHotel(int capacity);
		~MapHotel();
		int hash(const std::string key);
		int insertHotel(const std::string key, const Hotel value);
		Hotel searchHotel(const std::string key);
		int deleteHotel(const std::string key);
		void lastComparisons();

		const std::string returnKey(int hash);
		Hotel returnValue(int hash);
};
#endif
