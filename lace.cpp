#include "lace.h"


lace::Num::Num(std::string name) {
	this->name = name;
}

lace::Num::Num(std::string name, lace::prim value) {
	this->name = name;
	this->value = value;
}

lace::Set::Set(std::string name) {
	this->name = name;
}

lace::Set::Set(std::string name, std::vector<lace::prim> vec) {
	this->name = name;
	this->data = vec;
}

std::string lace::LaceType::getName() {
	return this->name;
}

lace::Expression::Expression(std::string expr) {
	this->expr_raw = expr;
}

lace::Expression& lace::Expression::withInput(lace::Set set) {
	this->input_sets.push_back(set);

	return *this;
}

lace::Expression& lace::Expression::withInput(lace::Num num) {
	this->input_nums.push_back(num);

	return *this;
}

lace::Expression& lace::Expression::withOutput(lace::Set* set) {
	this->output_sets.push_back(set);

	return *this;
}

lace::Expression& lace::Expression::withOutput(lace::Num* num) {
	this->output_nums.push_back(num);

	return *this;
}

lace::Expression& lace::Expression::evaluate() {
	//interpret -> codegen -> bind outputs

	return *this;
}