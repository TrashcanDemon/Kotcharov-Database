#ifndef H_DATAHANDLER
#define H_DATAHANDLER
#include <string>
#include <iostream>
#include <fstream>

typedef unsigned int uint;

class DatabaseHandler{
public:
	DatabaseHandler() = default;

	~DatabaseHandler();
	
	uint getOtherMontlyCosts(uint month, std::string city, uint age, std::string file);
	
	uint getHomeFoodCost(std::string city, uint age, std::string file);
	
	uint getCoffeeCost(std::string city, std::string coffee, std::string file);
	
	uint getCinemaCost(std::string city, std::string cinema, std::string file);
					
	uint getInstituteDinnerCost(std::string city, std::string institute, std::string file);
	
	uint getTransportCost(std::string city, std::string homeAddress,
						  std::string institute, std::string file);
};
#endif
