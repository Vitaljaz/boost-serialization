#include <boost/serialization/export.hpp>

#include "person.h"
#include "policeman.h"
#include "sportsman.h"
#include "detective.h"

BOOST_CLASS_EXPORT(Person);
BOOST_CLASS_EXPORT(Policeman);
BOOST_CLASS_EXPORT(Sportsman);
BOOST_CLASS_EXPORT(Detective);