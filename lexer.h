#pragma once

#include <variant>
#include "lace.h"

namespace lace::lexer {
	enum class TokenType {
		/* symbolic */
		PLUS, MINUS, BSLASH,
		STAR, SLASH, TILDE,
		LPAREN, RPAREN, 
		LBRACE, RBRACE, 
		LBRACKET, RBRACKET,
		CARET, UTRI, DTRI, 
		EQ, NEQ, DEQ,
		ARROW, DARROW, EXCL, PIPE,
		LT, LTEQ, GT, GTEQ,
		COMMA, PERIOD, HASH,

		NUM, IDENT,

		/* label */
		LET, DO, END, SQRT, ABS,
		SETTYPE, NUMTYPE, FUNCTYPE, INF,
		RSET, ZSET, QSET, ESET,
		ELEM, SUBSET, PSUBSET, 
		UNION, INTER, SUM, SIG
	};

	struct Token {
		TokenType type;
		std::optional<std::variant<double, unsigned char>> value;
	};

	class Lexer {
		char peek();
		char get();
		Token build_ident();
		Token build_num();
		const char* beg;

	public:
		Token next();
		std::vector<Token> build_token_stream(char* input);
	};

	bool is_space(char c);
	bool is_digit(char c);
	bool is_ident(char c);

} 