#include "WyjatkiDaty.hpp"

WyjatkiDaty::WyjatkiDaty(std::string ss) throw() : s(ss) {}

WyjatkiDaty::~WyjatkiDaty() throw() {}

const char*WyjatkiDaty::what() const throw() { return s.c_str(); }
