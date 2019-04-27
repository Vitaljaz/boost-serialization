#pragma once

#include "serialization.h"


class Person
{
public:
	int age;
	double height; 
	double weight; 
	std::string name;
	std::vector<int> favoriteNumbers;

	virtual void printInfo() = 0;
	virtual double indexOfHealth() = 0;

	Person();
	~Person();

private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar &BOOST_SERIALIZATION_NVP(name);
		ar &BOOST_SERIALIZATION_NVP(age);
		ar &BOOST_SERIALIZATION_NVP(weight);
		ar &BOOST_SERIALIZATION_NVP(height);
		ar &BOOST_SERIALIZATION_NVP(favoriteNumbers);
	}
};

