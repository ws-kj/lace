#pragma once

#include "lace.h"
#include "lexer.h"

using namespace lace;

namespace lace::parser {

	class ASTNode {
	public:
		virtual ~ASTNode() {}
	};

	class IdentNode : public parser::ASTNode {
		std::string label;

	public:
		IdentNode(std::string label) : label(label) {}
	};

	class NumNode : public parser::ASTNode {
		lace::prim value;

	public:
		NumNode(lace::prim value) : value(value) {}
	};

	class BinaryNode : public parser::ASTNode {
		lexer::TokenType type;
		std::unique_ptr<parser::ASTNode> left, right;

	public:
		BinaryNode(lexer::TokenType type,
			std::unique_ptr<parser::ASTNode> left, std::unique_ptr<parser::ASTNode> right) :
			type(type), left(std::move(left)), right(std::move(right)) {}

	};

	class UnaryNode : public parser::ASTNode {
		lexer::TokenType type;
		std::unique_ptr<parser::ASTNode> target;
		
	public:
		UnaryNode(lexer::TokenType type, std::unique_ptr<parser::ASTNode> target) : 
			type(type), target(std::move(target)) {}
	};

	class ContainNode : public parser::ASTNode {
		lexer::TokenType type;
		std::vector<std::unique_ptr<parser::ASTNode>> contents;

	public:
		ContainNode(lexer::TokenType type, std::vector<std::unique_ptr<parser::ASTNode>> contents) : 
			type(type), contents(std::move(contents)) {}
	};

	class ReservedNode : public parser::ASTNode {
		lexer::TokenType type;

	public:
		ReservedNode(lexer::TokenType type) : type(type) {}
	};

	class CallNode : public parser::ASTNode {
		lexer::Token callee;
		std::vector<std::unique_ptr<parser::ASTNode>> args;

	public:
		CallNode(lexer::Token callee, std::vector<std::unique_ptr<parser::ASTNode>> args) :
			callee(callee), args(std::move(args)) {}
	};

}