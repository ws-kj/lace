#include "lexer.h"

using namespace lace::lexer;


std::vector<Token> Lexer::build_token_stream(char* input) {
	std::vector<Token> stream;

	return stream;
}

Token Lexer::next() {
	while (is_space(this->peek())) this->get();

	if (is_digit(peek()))
		return this->build_num();
	if (is_ident(peek()))
		return this->build_ident();

	switch (peek()) {
		case '+':
			return Token{ TokenType::PLUS };
		case '-':
			return Token{ TokenType::MINUS };
		case '*':
			return Token{ TokenType::STAR };
		case '/':
			//build /\ 
			return Token{ TokenType::SLASH };
		case '\\':
			//build \/
			return Token{ TokenType::BSLASH };
		case '~':
			return Token{ TokenType::TILDE };
		case '(':
			return Token{ TokenType::LPAREN };
		case ')':
			return Token{ TokenType::RPAREN };
		case '{':
			return Token{ TokenType::LBRACE };
		case '}':
			return Token{ TokenType::RBRACE };
		case '[':
			return Token{ TokenType::LBRACKET };
		case ']':
			return Token{ TokenType::RBRACKET };
		case '^':
			return Token{ TokenType::CARET };
		case '=':
			//build ==
			return Token{ TokenType::EQ };
		case '!':
			//build !=
			return Token{ TokenType::EXCL };
		case '<':
			// buld <=
			return Token{ TokenType::LT };
		case '>':
			// build >=
			return Token{ TokenType::GT };
		case ',':
			return Token{ TokenType::COMMA };
		case '.':
			return Token{ TokenType::PERIOD };
		case '|':
			return Token{ TokenType::PIPE };
	}
}

char Lexer::peek() {
	return *(this->beg);
}

char Lexer::get() {
	return *(this->beg++);
}
 
bool is_space(char c) {
	switch (c) {
	case ' ':
	case '\r':
	case '\t':
		return true;
	default:
		return false;
	}
}

bool is_digit(char c) {
	if (isdigit((int)c))
		return true;
	else
		return false;
}

bool is_ident(char c) {
	if (isalpha((int)c) || c == '_')
		return true;
	else
		return false;
}
