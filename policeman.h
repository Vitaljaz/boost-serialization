#pragma once

#include "person.h"
#include "serialization.h"
#include <boost/serialization/shared_ptr.hpp>


class Policeman: public Person
{
public:
	Policeman(int rang, std::string gun, bool onDuty);
	Policeman();
	~Policeman();

	void printInfo();
	double indexOfHealth() override;

	int rang;
	bool onDuty;
	std::string gun;
	boost::shared_ptr<Person> obj;


private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Person);
		ar &BOOST_SERIALIZATION_NVP(rang);
		ar &BOOST_SERIALIZATION_NVP(onDuty);
		ar &BOOST_SERIALIZATION_NVP(gun);
		ar &BOOST_SERIALIZATION_NVP(obj);
	}
};

