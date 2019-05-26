#pragma once
#include "policeman.h"
#include "sportsman.h"
#include "serialization.h"
#include <boost/serialization/shared_ptr.hpp>

#include "class_helper.h"

class Detective: public Policeman, public Sportsman
{
public:
	Detective();

	Detective(std::string name, int age, int height, int weight, int rang, int number_of_investigate,
				int salary, std::string gun, bool onDuty, std::string body_type,
				std::string favorite_sport);


	~Detective();

	Helper helper;
	Helper *helper2 = new Helper();
	Helper *helper_ptr = &helper;
	Helper &helper_rf = *helper2;
	Helper &helper_rf2 = helper;

	int number_of_investigate;
	int salary;
	std::vector<int> favoriteNumbers;

	void printInfo();

private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Policeman);
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Sportsman);
		ar &BOOST_SERIALIZATION_NVP(favoriteNumbers);
		ar &BOOST_SERIALIZATION_NVP(number_of_investigate);
		ar &BOOST_SERIALIZATION_NVP(salary);
		ar &BOOST_SERIALIZATION_NVP(helper);
		ar &BOOST_SERIALIZATION_NVP(helper_ptr);
		ar &BOOST_SERIALIZATION_NVP(helper_rf);
		ar &BOOST_SERIALIZATION_NVP(helper_rf2);
	}
};

