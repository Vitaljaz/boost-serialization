#pragma once
#include "serialization.h"

class Helper {
private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {	}
};

class HelperWithParent : public virtual Helper {
private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {	}
};