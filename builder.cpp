#include "lace.h"
#include "lexer.h"

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

std::string LaceType::get_name() {
	return this->name;
}

Expression::Expression(const char* expr) {
	this->expr_raw = expr;
}

Expression& Expression::with_input(Set set) {
	this->input_sets.push_back(set);

	return *this;
}

Expression& Expression::with_input(Num num) {
	this->input_nums.push_back(num);

	return *this;
}

Expression& Expression::with_output(Set* set) {
	this->output_sets.push_back(set);

	return *this;
}

Expression& Expression::with_output(Num* num) {
	this->output_nums.push_back(num);

	return *this;
}

Expression& Expression::evaluate() {
	//interpret -> codegen -> bind outputs
	lexer::Lexer l;
	std::vector<lexer::Token> tokens = l.build_token_stream(this->expr_raw);

	for (const auto& t : tokens) {
		std::cout << "Token: " << (int)t.type;
		if (t.value) 
			std::cout << " Value: ";

		if (t.type == lexer::TokenType::NUM)
			std::cout << std::get<double>(t.value.value());
		else if (t.type == lexer::TokenType::IDENT)
			std::cout << std::get<std::string>(t.value.value());

		std::cout << std::endl;
	}

	return *this;
}