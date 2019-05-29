#pragma once

#include "serialization.h"
#include "class_helper.h"

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


	Helper helper;
	Helper *helper_ptr = &helper;
	Helper &helper_rf = helper;

	HelperWithParent h_parent;
	HelperWithParent *h_parent_ptr = &h_parent;

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
		ar &BOOST_SERIALIZATION_NVP(helper);
		ar &BOOST_SERIALIZATION_NVP(helper_ptr);
		ar &BOOST_SERIALIZATION_NVP(helper_rf);
		ar &BOOST_SERIALIZATION_NVP(h_parent_ptr);
	}
};

