#ifdef TEXT_ARCHIVE

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using Serializer = boost::archive::text_oarchive;
using Deserializer = boost::archive::text_iarchive;

#else

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

using Serializer = boost::archive::xml_oarchive;
using Deserializer = boost::archive::xml_iarchive;

#endif

#include "class_master.h"