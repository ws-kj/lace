#include "lexer.h"

using namespace lace;

std::vector<lexer::Token> lexer::Lexer::build_token_stream(const char* input) {
	std::vector<Token> stream;

	this->beg = input;

	while (this->peek())
		stream.push_back(this->next());

	return stream;
}

lexer::Token lexer::Lexer::next() {
	while (is_space(this->peek())) this->get();

	switch (peek()) {
		case '+':
			return lexer::Token{ lexer::TokenType::PLUS };

		case '-':
			return lexer::Token{ lexer::TokenType::MINUS };

		case '*':
			return lexer::Token{ lexer::TokenType::STAR };

		case '/':
			if (this->get() == '\\')
				return lexer::Token{ lexer::TokenType::UTRI };
			else
				this->back();
			return lexer::Token{ lexer::TokenType::SLASH };

		case '\\':
			if (this->get() == '/')
				return lexer::Token{ lexer::TokenType::DTRI };
			else
				this->back();
			return lexer::Token{ lexer::TokenType::BSLASH };

		case '~':
			return lexer::Token{ lexer::TokenType::TILDE };

		case '(':
			return lexer::Token{ lexer::TokenType::LPAREN };

		case ')':
			return lexer::Token{ lexer::TokenType::RPAREN };

		case '{':
			return lexer::Token{ lexer::TokenType::LBRACE };

		case '}':
			return lexer::Token{ lexer::TokenType::RBRACE };

		case '[':
			return lexer::Token{ lexer::TokenType::LBRACKET };

		case ']':
			return lexer::Token{ lexer::TokenType::RBRACKET };

		case '^':
			return lexer::Token{ lexer::TokenType::CARET };

		case '=':
			if (this->get() == '=')
				return lexer::Token{ lexer::TokenType::DEQ };
			else
				this->back();
			return lexer::Token{ lexer::TokenType::EQ };

		case '!':
			if (this->get() == '=')
				return lexer::Token{ lexer::TokenType::NEQ };
			else
				this->back();
			return lexer::Token{ lexer::TokenType::EXCL };

		case '<':
			if (this->get() == '=')
				return lexer::Token{ lexer::TokenType::LTEQ };
			else
				this->back();
			return lexer::Token{ lexer::TokenType::LT };

		case '>':
			if (this->get() == '=')
				return lexer::Token{ lexer::TokenType::GTEQ };
			else
				this->back();
			return lexer::Token{ lexer::TokenType::GT };

		case ',':
			return lexer::Token{ lexer::TokenType::COMMA };

		case '.':
			return lexer::Token{ lexer::TokenType::PERIOD };

		case '|':
			return lexer::Token{ lexer::TokenType::PIPE };

		case ':':
			char next = this->get();
			switch (next) {
			case 'Z':
				return lexer::Token{ lexer::TokenType::ZSET };
			case 'Q':
				return lexer::Token{ lexer::TokenType::QSET };
			case 'R':
				return lexer::Token{ lexer::TokenType::RSET };
			case 'E':
				return lexer::Token{ lexer::TokenType::ESET };
			default:
				this->back();
			}
			return lexer::Token{ lexer::TokenType::COLON };
	}

	if (is_digit(peek())) {
		try {
			return this->build_num();
		} catch (std::exception& e) { throw e; }
	}

	if (is_ident(peek()))
		return this->build_ident();

	throw std::exception("lace: invalid character");
}

lexer::Token lexer::Lexer::build_ident() {
	std::string label;
	label += this->get();
	while (lexer::is_ident(this->peek()) || lexer::is_digit(this->peek())) label += this->get();

	if(label == "let")
		return lexer::Token{ lexer::TokenType::LET };
	else if (label == "do")
		return lexer::Token{ lexer::TokenType::DO };
	else if (label == "sqrt")
		return lexer::Token{ lexer::TokenType::SQRT };
	else if (label == "abs")
		return lexer::Token{ lexer::TokenType::ABS };
	else if (label == "set")
		return lexer::Token{ lexer::TokenType::SETTYPE };
	else if (label == "num")
		return lexer::Token{ lexer::TokenType::NUMTYPE };
	else if (label == "func")
		return lexer::Token{ lexer::TokenType::FUNCTYPE };
	else if (label == "inf")
		return lexer::Token{ lexer::TokenType::INF };
	else if (label == "elem")
		return lexer::Token{ lexer::TokenType::ELEM };
	else if (label == "subset")
		return lexer::Token{ lexer::TokenType::SUBSET };
	else if (label == "psubset")
		return lexer::Token{ lexer::TokenType::PSUBSET };
	else if (label == "union")
		return lexer::Token{ lexer::TokenType::UNION };
	else if (label == "inter")
		return lexer::Token{ lexer::TokenType::INTER };
	else if (label == "sum")
		return lexer::Token{ lexer::TokenType::SUM };
	else if (label == "sigma")
		return lexer::Token{ lexer::TokenType::SIGMA };

	return lexer::Token{ lexer::TokenType::IDENT, label };
}

lexer::Token lexer::Lexer::build_num() {
	std::string label;
	label += this->get();
	while (lexer::is_digit(this->peek()) || this->peek() == '.') label += this->get();

	try {
		double num = std::stod(label);
		return lexer::Token{ lexer::TokenType::NUM, num };
	}
	catch (std::invalid_argument& e) {
		throw("lace: invalid num construction");
	}
}

char lexer::Lexer::peek() {
	return *(this->beg);
}

char lexer::Lexer::get() {
	return *(this->beg++);
}
 
char lexer::Lexer::back() {
	return *(this->beg--);
}

bool lexer::is_space(char c) {
	switch (c) {
	case ' ':
	case '\r':
	case '\t':
		return true;
	default:
		return false;
	}
}

bool lexer::is_digit(char c) {
	if (isdigit((int)c))
		return true;
	else
		return false;
}

bool lexer::is_ident(char c) {
	if (isalpha((int)c) || c == '_')
		return true;
	else
		return false;
}
