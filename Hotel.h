#ifndef HOTEL
#define HOTEL
#import<string>

class Hotel{
	private:
		std::string cityName;
		double stars;
		double price;
		std::string countryName;
		std::string address;

	public:
		std::string hotelName;
		Hotel();
		Hotel(std::string hotelName, std::string cityName, double stars, double price, std::string countryName, std::string address);
		const std::string getName();
		void printHotel();
		const std::string hotelLabel() const;
		bool operator !=(const Hotel value);
};
#endif
