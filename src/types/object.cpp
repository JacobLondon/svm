#include "object.hpp"

namespace svm {

Object::Object(uint8_t type)
: type(type)
{}

Object::~Object()
{}

} // svm