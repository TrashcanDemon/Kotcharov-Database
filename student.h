#ifndef H_STUDENT
#define H_STUDENT
#include <string>
#include <iostream>

typedef unsigned int uint;

class Student{
private:
	std::string _city;
	std::string _homeAddress;
	std::string _institute;
	std::string _cinema;
	std::string _coffee;
	uint _age;
public:
	Student(std::string city,
			std::string homeAddress,
			std::string institute,
			std::string cinema,
			std::string coffee,
			uint age);
	~Student();
	uint getWorkdayCost(std::string fileCost, std::string fileInst, std::string fileTrans);
	uint getWeekandCost(std::string fileCost, std::string fileCofcin);
	int getCosts(uint month, uint workDays, uint weekends, std::string fileCost, std::string fileCofcin, std::string fileInst, std::string fileTrans);
};
#endif