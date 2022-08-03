#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <optional>

#include "lexer.h"

namespace lace 
{
	template <typename T>
	constexpr bool is_lacetype = (std::is_same<T, Set>::value || std::is_same<T, Num>::value);
	
	typedef double prim;

	class LaceType 
	{
	protected:
		std::string name;
	public:
		std::string getName();
	};

	class Num : public LaceType
	{
	public:
		Num(std::string name);
		Num(std::string name, prim value);
		prim value;
	};

	class Set : public LaceType
	{
	public:
		Set(std::string name);
		Set(std::string name, std::vector<prim> vec);

		std::vector<prim> data;

	};

	class Expression 
	{
		std::vector<Set> input_sets;
		std::vector<Num> input_nums;

		std::vector<Set*> output_sets;
		std::vector<Num*> output_nums;

		std::string expr_raw;

	public:
		Expression(std::string expr);

		Expression& withInput(Num num);
		Expression& withInput(Set set);

		Expression& withOutput(Num* num);
		Expression& withOutput(Set* set);

		Expression& evaluate();
	};
}
