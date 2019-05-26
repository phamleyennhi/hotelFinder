#ifndef HASHHOTEL
#define HASHHOTEL
#import<string>
#import "Hotel.h"

class HashHotel{
	private:
		std::string key;
		Hotel value;

	public:
		HashHotel(std::string key, Hotel value); 
		std::string getKey();
		Hotel getValue();
		void setValue(std::string key, Hotel value);
};

#endif