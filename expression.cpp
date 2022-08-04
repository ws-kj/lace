#include "lace.h"
#include "lexer.h"
#include "parser.h"

using namespace lace;

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
	std::vector<lexer::Token> tokens = lexer::Lexer().build_token_stream(this->expr_raw);

	for (const auto& t : tokens) {
		std::cout << "Token: " << (int)t.type;
		if (t.value) 
			std::cout << " Value: ";

		if (t.type == lexer::TokenType::NUM)
			std::cout << std::get<lace::prim>(t.value.value());
		else if (t.type == lexer::TokenType::IDENT)
			std::cout << std::get<std::string>(t.value.value());

		std::cout << std::endl;
	}

	return *this;
}