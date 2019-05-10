#include <iostream>
#include <fstream>

#include "person.h"
#include "policeman.h"

#include "archive.h"
#include "serialization.h"

#include <boost/serialization/scoped_ptr.hpp>
#include <boost/scoped_ptr.hpp>

void test_1() 
{
	std::cout << "=============== TEST 1 ===============" << std::endl;
	Policeman *john = new Policeman(10, "Shootgun", false);
	john->printInfo();
	std::ofstream ofs("policeman.xml");
	Serializer oa(ofs);
	oa << BOOST_SERIALIZATION_NVP(john);
	ofs.close();
	delete john;

	std::cout << "\nAfter serialization: " << std::endl;
	Policeman *mike;
	std::ifstream ifs("policeman.xml");
	Deserializer ia(ifs);
	ia >> BOOST_SERIALIZATION_NVP(mike);
	ifs.close();
	mike->printInfo();
	std::cout << "=============== TEST 1 ===============" << std::endl;
	delete mike;
}

void test_2()
{
	std::cout << "\n=============== TEST 2 ===============" << std::endl;
	boost::scoped_ptr<Policeman> john{ new Policeman{5, "m4", true} };
	std::ofstream ofs("policeman.xml");
	Serializer oa(ofs);
	oa << BOOST_SERIALIZATION_NVP(john);
	ofs.close();
	john->printInfo();
	std::cout << "\nAfter deseralization: " << std::endl;

	boost::scoped_ptr<Policeman> mike;
	std::ifstream ifs("policeman.xml");
	Deserializer ia(ifs);
	ia >> BOOST_SERIALIZATION_NVP(mike);
	ifs.close();
	mike->printInfo();
	std::cout << "=============== TEST 2 ===============" << std::endl;
}

void test_3() 
{
	std::cout << "\n=============== TEST 3 ===============" << std::endl;
	Policeman alex{ 10, "sniper", true };
	Policeman &andrew = alex;
	alex.printInfo();
	std::ofstream ofs("policeman.xml");
	Serializer oa(ofs);
	oa << BOOST_SERIALIZATION_NVP(andrew);
	ofs.close();
	std::cout << "\nAfter serialization: " << std::endl;

	Policeman kendrick;
	Policeman &jacob = kendrick;
	std::ifstream ifs("policeman.xml");
	Deserializer ia(ifs);
	ia >> BOOST_SERIALIZATION_NVP(kendrick);
	ifs.close();
	kendrick.printInfo();
	std::cout << "=============== TEST 3 ===============" << std::endl;

}

int main()
{
	test_1();
	test_2();
	test_3();
	return 0;
}