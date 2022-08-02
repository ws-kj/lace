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

lace::Result::Result(lace::Set data) {
	this->data = data;
}
lace::Result::Result(lace::Set data, std::string err) {
	this->data = data;
	this->err = err;
}

std::optional<lace::Set> lace::Result::getData() {
	if (this->err == "")
		return this->data;
	else
		return std::nullopt;
}
std::string lace::Result::getError() {
	return this->err;
}