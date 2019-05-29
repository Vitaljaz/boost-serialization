#include "detective.h"
#include <iostream>


Detective::Detective()
{
}

Detective::Detective(std::string name, int age, int height, int weight, int rang, int number_of_investigate, 
						int salary, std::string gun, bool onDuty, std::string body_type,
						std::string favorite_sport)
{
	this->name = name;
	this->age = age;
	this->height = height;
	this->weight = weight;
	this->rang = rang;
	this->number_of_investigate = number_of_investigate;
	this->salary = salary;
	this->gun = gun;
	this->onDuty = onDuty;
	this->body_type = body_type;
	this->favorite_sport = favorite_sport;
	this->max_weight = 100;
	favoriteNumbers.push_back(1);
	favoriteNumbers.push_back(2);
	favoriteNumbers.push_back(5);
	favoriteNumbers.push_back(7);
}


Detective::~Detective()
{
}

void Detective::printInfo()
{
	std::cout << "Information about detective: "<< std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << "Salary: " << salary << std::endl;
	std::cout << "Number of investigate: " << number_of_investigate << std::endl;
	std::cout << "Body type: " << body_type << std::endl;
	std::cout << "Favorite sport: " << favorite_sport << std::endl;
	std::cout << "Rang: " << rang << std::endl;
	std::cout << "Personal gun: " << gun << std::endl;
	std::cout << "On duty: " << onDuty << std::endl;
}
