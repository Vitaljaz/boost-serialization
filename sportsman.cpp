#include "sportsman.h"



Sportsman::Sportsman()
{
}

Sportsman::Sportsman(int max_weight, std::string body_type, std::string favorite_sport)
{
	this->max_weight = max_weight;
	this->body_type = body_type;
	this->favorite_sport = favorite_sport;
	favoriteNumbers.push_back(45);
	favoriteNumbers.push_back(33);
}


Sportsman::~Sportsman()
{
}
