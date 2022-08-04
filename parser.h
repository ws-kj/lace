#pragma once

#include "lace.h"
#include "lexer.h"

using namespace lace;

namespace lace::parser {
	enum class OpType {

	 };

	class ASTNode {
		std::optional<std::shared_ptr<ASTNode>> left;
		std::optional<std::shared_ptr<ASTNode>> mid;
		std::optional<std::shared_ptr<ASTNode>> right;

	public:
		ASTNode(lexer::Token token);

		lexer::Token token;
	};
}