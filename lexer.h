#pragma once

#include "lace.h"

namespace lace::lexer {
	enum Token {
		/* symbolic tokens */
		T_PLUS, T_MINUS, T_BSLASH,
		T_STAR, T_SLASH, T_TILDE,
		T_LPAREN, T_RPAREN, 
		T_LBRACE, T_RBRACE, 
		T_LBRACKET, T_RBRACKET,
		T_CARET, T_UTRI, T_DTRI, 
		T_EQ, T_NEQ, T_DEQ,
		T_ARROW, T_BARROW, T_EXCL, T_BAR,
		T_LT, T_LTEQ, T_GT, T_GTEQ,
		T_COMMA, T_PERIOD, T_EOF, T_HASH,

		/* literal tokens */
		T_NUMLIT, T_CHARLIT,

		/* label tokens */
		T_LET, T_DO, T_END,
		T_SET, T_NUM, T_FUNC, T_INF,
		T_RSET, T_ZSET, T_QSET, T_ESET,
		T_ELEM, T_SUBSET, T_PSUBSET, 
		T_UNION, T_INTER, T_SUM, T_SIG,
		T_SQRT, T_ABS
	};

}