#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <sstream>
#include "Hotel.h"
#include "HashHotel.h"
#include "MapHotel.h"
#include "MapCity.h"
#include "HotelFinder.h"

using namespace std;

int main(int argc, char *args[]){

	//START ARG
	std::string inputfile = "";
	for (int i = 0; i < argc; i++){
		if (string(args[i]) == "-f" && i < argc-1){
			inputfile = args[i+1];
		}
	}
	if (inputfile == ""){
		cout << "Usage ./hotelFinder -f <filename>" << endl;
		return EXIT_SUCCESS;
	}

	//SETUP
	HotelFinder finder(100010);
	finder.readFile(inputfile);


	//COMMAND PROCESSING
	bool run = true;
	string query;
	while(run){
		cin>>query;
		if(!finder.command(query)) run = false;
	}

	
	return EXIT_SUCCESS;
}