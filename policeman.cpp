#include "policeman.h"

#include <iostream>

Policeman::Policeman(int rang, std::string gun, bool onDuty) 
{
	name = "Anthony";
	weight = 86.4;
	height = 185.9;
	age = 30;
	favoriteNumbers.push_back(10);
	favoriteNumbers.push_back(9);
	this->rang = rang;
	this->gun = gun;
	this->onDuty = onDuty;
}

double Policeman::indexOfHealth() {
	return (height / weight + age);
}

void Policeman::printInfo() {
	std::cout << "Information about policeman: " << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << "Rang: " << rang << std::endl;
	std::cout << "Personal gun: " << gun << std::endl;
	std::cout << "On duty: " << onDuty << std::endl;
}

Policeman::Policeman()
{
}

Policeman::~Policeman()
{
}
