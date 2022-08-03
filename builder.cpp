#include "lace.h"

using namespace lace;

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

std::string LaceType::getName() {
	return this->name;
}

Expression::Expression(std::string expr) {
	this->expr_raw = expr;
}

Expression& Expression::withInput(Set set) {
	this->input_sets.push_back(set);

	return *this;
}

Expression& Expression::withInput(Num num) {
	this->input_nums.push_back(num);

	return *this;
}

Expression& Expression::withOutput(Set* set) {
	this->output_sets.push_back(set);

	return *this;
}

Expression& Expression::withOutput(Num* num) {
	this->output_nums.push_back(num);

	return *this;
}

Expression& Expression::evaluate() {
	//interpret -> codegen -> bind outputs

	return *this;
}