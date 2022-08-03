#include "lace.h"


lace::Num::Num(std::string name, lace::prim value) {
	this->name = name;
	this->value = value;
}

lace::prim lace::Num::getValue() {
	return this->value;
}

lace::Set::Set() {}

lace::Set::Set(std::string name, std::vector<lace::prim>& vec) {
	this->name = name;
	this->data = vec;
}

std::string lace::LaceType::getName() {
	return this->name;
}

std::vector<lace::prim> lace::Set::asVec() {
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

lace::Expression::Expression(std::string expr) {
	this->expr_raw = expr;
}

lace::Expression& lace::Expression::withInput(lace::Num num) {
	this->input_nums.push_back(num);

	return *this;
}
lace::Expression& lace::Expression::withInput(lace::Set set) {
	this->input_sets.push_back(set);

	return *this;
}

lace::Result lace::Expression::evaluate() {

	return lace::Result(lace::Set("B", std::vector<lace::prim>(3, 3)), "");
}