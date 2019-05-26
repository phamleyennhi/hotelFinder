hotelFinder: main.o Hotel.o HashHotel.o MapHotel.o MapCity.o HotelFinder.o
	g++  Hotel.o HashHotel.o MapHotel.o MapCity.o HotelFinder.o main.o -o hotelFinder

main.o: main.cpp
	g++ -c main.cpp

Hotel.o: Hotel.cpp Hotel.h
	g++ -c Hotel.cpp 

HashHotel.o: HashHotel.cpp HashHotel.h
	g++ -c HashHotel.cpp 

MapHotel.o: MapHotel.cpp MapHotel.h
	g++ -c MapHotel.cpp  

MapCity.o: MapCity.cpp MapCity.h
	g++ -c MapCity.cpp 

HotelFinder.o: HotelFinder.cpp HotelFinder.h
	g++ -c HotelFinder.cpp
clean:
	rm *.o hotelFinder