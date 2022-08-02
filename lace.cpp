#include "lace.h"

lace::Set::Set() {}

lace::Set::Set(std::vector<lace::Num>& vec) {
	this->data = vec;
}

lace::Set::Set(std::string name) {
	this->name = name;
}

lace::Set::Set(std::vector<lace::Num>& vec, std::string name) {
	this->name = name;
	this->data = vec;
}

std::string lace::Set::getName() {
	return this->name;
}

std::vector<lace::Num> lace::Set::asVec() {
	return this->data;
}

