#pragma once

#include "person.h"
#include "serialization.h"

class Sportsman : public virtual Person
{
public:
	Sportsman();
	Sportsman(int max_weight, std::string body_type, std::string favorite_sport);
	~Sportsman();


	std::string body_type;
	std::string favorite_sport;
	int max_weight;

	std::vector<int> favoriteNumbers;

private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Person);
		ar &BOOST_SERIALIZATION_NVP(body_type);
		ar &BOOST_SERIALIZATION_NVP(favoriteNumbers);
		ar &BOOST_SERIALIZATION_NVP(max_weight);
		ar &BOOST_SERIALIZATION_NVP(favoriteNumbers);
	}
};

