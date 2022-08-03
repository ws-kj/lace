#pragma once

#include <variant>
#include "lace.h"

namespace lace::lexer {
	enum class TokenType {
		/* symbols */
		PLUS, MINUS, BSLASH,
		STAR, SLASH, TILDE,
		LPAREN, RPAREN, 
		LBRACE, RBRACE, 
		LBRACKET, RBRACKET,
		CARET, UTRI, DTRI, 
		EQ, NEQ, DEQ, COLON,
		ARROW, DARROW, EXCL, PIPE,
		LT, LTEQ, GT, GTEQ,
		COMMA, PERIOD, HASH,

		/* data */
		NUM, IDENT, 

		/* keywords */
		LET, DO, END, SQRT, ABS,
		SETTYPE, NUMTYPE, FUNCTYPE, INF,
		RSET, ZSET, QSET, ESET,
		ELEM, SUBSET, PSUBSET, 
		UNION, INTER, SUM, SIGMA,

		INPUT_END
	};

	struct Token {
		TokenType type;
		std::optional<std::variant<lace::prim, std::string>> value;
	};

	class Lexer {
		const char* beg;

		char peek();
		char get();
		char back();
		char look();

		Token build_ident();
		Token build_num();

	public:
		Token next();
		std::vector<Token> build_token_stream(const char* input);
	};

	bool is_space(char c);
	bool is_digit(char c);
	bool is_ident(char c);

} 