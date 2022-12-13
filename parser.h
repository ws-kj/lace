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
		std::unique_ptr<parser::ASTNode> contents;

	public:
		ContainNode(lexer::TokenType type, std::unique_ptr<parser::ASTNode> contents) : 
			type(type), contents(std::move(contents)) {}
	};
    
    class ListNode : public parser::ASTNode{
		std::vector<std::unique_ptr<parser::ASTNode>> items;

	public:
		ListNode(std::vector<std::unique_ptr<parser::ASTNode>> items) : items(std::move(items)) {}
	};


	class ReservedNode : public parser::ASTNode {
		lexer::TokenType type;

	public:
		ReservedNode(lexer::TokenType type) : type(type) {}
	};

	class ProtoNode : public parser::ASTNode {
		std::string name;
		std::vector<std::string> arg_names;

	public:
		ProtoNode(std::string name, std::vector<std::string> arg_names) :
			name(name), arg_names(std::move(arg_names)) {}
	};

	class FuncNode : public parser::ASTNode {
		std::unique_ptr<parser::ProtoNode> proto;
		std::unique_ptr<parser::ASTNode> body;

	public:
		FuncNode(std::unique_ptr<parser::ProtoNode> proto, std::unique_ptr<parser::ASTNode> body) :
			proto(std::move(proto)), body(std::move(body)) {}
	};

	class CallNode : public parser::ASTNode {
		lexer::Token callee;
		std::vector<std::unique_ptr<parser::ASTNode>> args;

	public:
		CallNode(lexer::Token callee, std::vector<std::unique_ptr<parser::ASTNode>> args) :
			callee(callee), args(std::move(args)) {}
	};

	class ElifNode : public parser::ASTNode {
		std::unique_ptr<parser::ASTNode> cond;
		std::unique_ptr<parser::ASTNode> body;

	public:
		ElifNode(std::unique_ptr<parser::ASTNode> cond, std::unique_ptr<parser::ASTNode> body) :
			cond(std::move(cond)), body(std::move(body)) {}
	};

	class IfNode : public parser::ASTNode {
		std::unique_ptr<parser::ASTNode> cond;
		std::unique_ptr<parser::ASTNode> body;
		
		std::vector<std::unique_ptr<parser::ElifNode>> elifs;
		std::optional<std::unique_ptr<parser::ASTNode>> else_body;

	public:
		IfNode(std::unique_ptr<parser::ASTNode> cond, std::unique_ptr<parser::ASTNode> body,
			std::vector<std::unique_ptr<parser::ElifNode>> elifs,
			std::optional<std::unique_ptr<parser::ASTNode>> else_body) :
			cond(std::move(cond)), body(std::move(body)), 
			elifs(std::move(elifs)), else_body(std::move(else_body)) {}
	};

}
