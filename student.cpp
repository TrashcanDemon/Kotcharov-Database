#include "student.h"
#include "datahandler.h"

Student::Student(std::string city,
				 std::string homeAddress,
				 std::string institute,
				 std::string cinema,
				 std::string coffee,
				 uint age){
	_city = city;
	_homeAddress = homeAddress;
	_institute =institute;
	_cinema = cinema;
	_coffee = coffee;
	_age = age;
}

Student::~Student(){
	std::cout << "Student annihilated." << std::endl << "--------------------" << std::endl;
}

uint Student::getWorkdayCost(std::string fileCost, std::string fileInst, std::string fileTrans){
   /* По рабочим дням расходы складываются из стоимости:
    - дороги до института и обратно 
    - обеда в институтской столовой
    - завтрака и обеда дома */

	DatabaseHandler databaseHandler;

    return static_cast<uint>(2 * databaseHandler.getTransportCost(_city, _homeAddress, _institute, fileTrans) +
        databaseHandler.getInstituteDinnerCost(_city, _institute, fileInst) +
		0.66 * databaseHandler.getHomeFoodCost(_city, _age, fileCost) + 0.5);
}

uint Student::getWeekandCost(std::string fileCost, std::string fileCofcin){
    /* По выходным дням расходы складываются из стоимости:
     - похода в кино (пешком)
     - похода  в кафе (пешком)
     - завтрака и обеда дома */

	DatabaseHandler databaseHandler;

    return static_cast<uint>(0.66 * databaseHandler.getHomeFoodCost(_city, _age, fileCost) + 
        databaseHandler.getCoffeeCost(_city, _coffee, fileCofcin) + databaseHandler.getCinemaCost(_city, _cinema, fileCofcin) + 0.5);
}

int Student::getCosts(uint month, uint workDays, uint weekends, std::string fileCost, std::string fileCofcin, std::string fileInst, std::string fileTrans) {
    /* Расходы:
     - по рабочим дням
     - по выходным дням
     - прочие расходы */

	DatabaseHandler databaseHandler;

    return workDays * getWorkdayCost(fileCost, fileInst, fileTrans) +
           weekends * getWeekandCost(fileCost, fileCofcin) + 
					  databaseHandler.getOtherMontlyCosts(month, _city, _age, fileCost);
}