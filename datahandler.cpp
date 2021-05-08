#include "datahandler.h"

DatabaseHandler::~DatabaseHandler(){
	std::cout << "Database Destroyed." << std::endl;
	std::cout << "-------------------" << std::endl;
}

uint DatabaseHandler::getOtherMontlyCosts(uint month, std::string city, uint age, std::string file){
    /* Получаем из базы данных средние по региону затраты в данном месяце 
     для людей данного возраста
    (по остальным статьям кроме еды, транспорта и развлечений) */
	uint othercosts = 0;
	std::string cityCheck;
	std::string ageCheck;
	
	std::ifstream costs;
	costs.open(file);
	
	if (!(costs.good())){
		std::cout << "Costs file not found. Returning 0.";
		return othercosts;
	}
	
	while (costs.good()){
		std::getline(costs, cityCheck, ',');
		if (cityCheck == city){
			std::getline(costs, ageCheck, ',');
			if (ageCheck == std::to_string(age)){
				std::getline(costs, cityCheck, ','); //skip food
				std::getline(costs, cityCheck, ','); //read cost
				othercosts = stoi(cityCheck);
				//std::cout << othercosts << std::endl;
				return othercosts;
			}
		}
		getline(costs, cityCheck);
	}
	return othercosts;
}

uint DatabaseHandler::getHomeFoodCost(std::string city, uint age, std::string file){
	// Получаем из базы данных средние по региону затраты на еду
	uint foodcosts = 0;
	std::string cityCheck;
	std::string ageCheck;
	
	std::ifstream costs;
	costs.open(file);
	
	if (!(costs.good())){
		std::cout << "Costs file not found. Returning 0.";
		return foodcosts;
	}
	
	while (costs.good()){
		std::getline(costs, cityCheck, ',');
		if (cityCheck == city){
			std::getline(costs, ageCheck, ',');
			if (ageCheck == std::to_string(age)){
				std::getline(costs, ageCheck, ','); //read foodcosts
				foodcosts = stoi(ageCheck);
				//std::cout << foodcosts << std::endl;
				return foodcosts;
			}
		}
		getline(costs, cityCheck);
	}
	return foodcosts;
}

uint DatabaseHandler::getCoffeeCost(std::string city, std::string coffee, std::string file) {

	std::string cofcinCheck;
	std::string cityCheck;
	std::string addressCheck;
	uint coffeeCost = 0;

	std::ifstream CofCin;
	CofCin.open(file);

	if (!(CofCin.good())){
		std::cout << "Coffee&Cinema file not found. Returning 0.";
		return coffeeCost;
	}
	
	while (CofCin.good()){
		std::getline(CofCin,cityCheck,',');
		if (cityCheck == city){
			std::getline(CofCin, cofcinCheck, ',');		//screw address
			std::getline(CofCin, cofcinCheck, ','); 	//read coffee
			if (cofcinCheck == coffee){
				std::getline(CofCin, cofcinCheck, ',');	//read coffeeCost
				coffeeCost = stoi(cofcinCheck);
				//std::cout << coffeeCost << std::endl;
				return coffeeCost;
			
			}
		}
		getline(CofCin, cityCheck);
	}
	return coffeeCost;
}

uint DatabaseHandler::getCinemaCost(std::string city, std::string cinema, std::string file) {

	std::string cofcinCheck;
	std::string cityCheck;
	std::string addressCheck;
	uint cinemaCost = 0;

	std::ifstream CofCin;
	CofCin.open(file);

	if (!(CofCin.good())){
		std::cout << "Coffee&Cinema file not found. Returning 0.";
		return cinemaCost;
	}
	
	while (CofCin.good()){
		std::getline(CofCin,cityCheck,',');
		if (cityCheck == city){
			std::getline(CofCin, cofcinCheck, ','); //screw address
			std::getline(CofCin, cofcinCheck, ',');	//screw coffee
			std::getline(CofCin, cofcinCheck, ',');	//screw coffeeCost
			std::getline(CofCin, cofcinCheck, ',');	//read cinema
			if (cofcinCheck == cinema){
				std::getline(CofCin, cofcinCheck, ',');	//read cinemaCost
				cinemaCost = stoi(cofcinCheck);
				//std::cout << cinemaCost << std::endl;
				return cinemaCost;
			}
		}
		getline(CofCin, cityCheck);
	}
	return cinemaCost;
}

uint DatabaseHandler::getInstituteDinnerCost(std::string city, std::string institute, std::string file) {

	std::string cityCheck;
	std::string instituteCheck;
	uint instituteCost = 0;

	std::ifstream Inst;
	
	Inst.open(file);
	
	if (!(Inst.good())){
		std::cout << "Institute file not found. Returning 0.";
		return instituteCost;
	}
	
	while (Inst.good()){
		std::getline(Inst,cityCheck,',');
		if (cityCheck == city){
			std::getline(Inst, instituteCheck, ',');
			if (instituteCheck == institute){
				std::getline(Inst, instituteCheck, ',');
				instituteCost = stoi(instituteCheck);
				//std::cout << instituteCost << std::endl;
				return instituteCost;
			}
		}
		getline(Inst, cityCheck);
	}
	return instituteCost;
}

uint DatabaseHandler::getTransportCost(std::string city, std::string homeAddress,
									   std::string institute, std::string file) {
    // Получаем из базы данных стоимость кратчайшей дороги до инстиутта
	std::string cityCheck;
	std::string addressCheck;
	std::string instituteCheck;
	uint transCost = 0;

	std::ifstream Trans;
	
	Trans.open(file);
	
	if (!(Trans.good())){
		std::cout << "Transport file not found. Returning 0.";
		return transCost;
	}
	
	while (Trans.good()){
		std::getline(Trans, cityCheck, ',');
		if (cityCheck == city){
			std::getline(Trans, addressCheck, ',');
			if (addressCheck == homeAddress){
				std::getline(Trans, instituteCheck, ',');
				if (instituteCheck == institute){
					std::getline(Trans, instituteCheck, ',');
					transCost = stoi(instituteCheck);
					//std::cout << transCost << std::endl;
					return transCost;
				}
			}
		}
		getline(Trans, cityCheck);
	}
	return transCost;
}

