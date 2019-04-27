#include <iostream>
#include <fstream>

#include "person.h"
#include "policeman.h"

#include "archive.h"
#include "serialization.h"

int main()
{
	Policeman *cop_Mike = new Policeman(10, "Deagle", true);
	std::cout << "Serialization start." << std::endl;
	std::ofstream ofs("policeman.xml");
	Serializer oa(ofs);
	oa << BOOST_SERIALIZATION_NVP(cop_Mike);
	ofs.close();
	std::cout << "Serialization is end." << std::endl;

	Policeman *cop_John = new Policeman();
	std::cout << "Deserialization start." << std::endl;
	std::ifstream ifs("policeman.xml");
	Deserializer ia(ifs);
	ia >> BOOST_SERIALIZATION_NVP(cop_John);
	ifs.close();
	std::cout << "Deserialization is end." << std::endl;

	cop_John->printInfo();
	std::cout << "Index of health: " << cop_John->indexOfHealth() << std::endl;

	delete cop_Mike;
	delete cop_John;
	return 0;
}