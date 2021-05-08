#include "student.h"
#include <iostream>
#include <string>

typedef unsigned int uint;

uint getDaysCount(uint month){
    // Вычисляем количество дней в месяце
	uint days;
	if (month == 2){
		days = 28;
	}
	if (month % 2 != 0){
		days = 31;
	}
	if ((month % 2 == 0)&&(month != 2)){
		days = 30;
	}
	//std::cout << days << std::endl;
	return days;
}

uint getWorkdays(uint month){
   // Получаем из базы данных число рабочих дней данном в месяце
	return getDaysCount(month) - 8;
}


int main(){
	uint month;
	uint age;
	std::string city;
	std::string homeAddress;
	std::string institute;
	std::string coffee;
	std::string cinema;

	std::cout << "Input city, home address, institute, cinema, coffee, age and current month number:" << std::endl;
	std::cin >> city >> homeAddress >> institute >> cinema >> coffee >> age >> month;
	Student student1(city, homeAddress, institute, cinema, coffee, age);
	
	uint daysCount = getDaysCount(month);
    uint workDays = getWorkdays(month);
    uint weekends = daysCount - workDays;
	
	std::string fileCost = "Costs.csv";
	std::string fileCofcin = "Caffe-and-cinema.csv";
	std::string fileInst = "Institute.csv";
	std::string fileTrans = "Transport.csv";
	
	uint cost = student1.getCosts(month, workDays, weekends, fileCost, fileCofcin, fileInst, fileTrans);
	
	if (cost == 0){
		std::cout << "It seems at least one of the variables is incorrect. Aborting." << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		return 0;
	}
	std::cout << "This student will spend about " << cost << " rubles this month." << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	return 0;
}
