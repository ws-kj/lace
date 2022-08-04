#include "lace.h"

using namespace lace;

std::string LaceType::get_name() {
	return this->name;
}

Num::Num(std::string name) {
	this->name = name;
}

Num::Num(std::string name, prim value) {
	this->name = name;
	this->value = value;
}

Set::Set(std::string name) {
	this->name = name;
}

Set::Set(std::string name, std::vector<prim> vec) {
	this->name = name;
	this->data = vec;
}
