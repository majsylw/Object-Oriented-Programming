#include "BrakKlucza.hpp"

BrakKlucza::BrakKlucza(std::string ss) throw() : s(ss) {}

BrakKlucza::~BrakKlucza() throw() {}

const char*BrakKlucza::what() const throw() { return s.c_str(); }
