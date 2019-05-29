#pragma once

#include "person.h"
#include "serialization.h"
#include <boost/serialization/shared_ptr.hpp>


class Policeman: public virtual Person
{
public:
	Policeman();
	Policeman(int rang, std::string gun, bool onDuty);
	~Policeman();

	void printInfo();
	double indexOfHealth() override;

	int rang;
	bool onDuty;
	std::string gun;
	int address = (int) this;
	boost::shared_ptr<Person> obj;
	std::vector<int> favoriteNumbers;


private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Person);
		ar &BOOST_SERIALIZATION_NVP(rang);
		ar &BOOST_SERIALIZATION_NVP(favoriteNumbers);
		ar &BOOST_SERIALIZATION_NVP(onDuty);
		ar &BOOST_SERIALIZATION_NVP(gun);
		ar &BOOST_SERIALIZATION_NVP(obj);
		ar &BOOST_SERIALIZATION_NVP(address);
	}
};

