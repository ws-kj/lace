#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <optional>

namespace lace 
{
	template <typename T>
	constexpr bool is_lacetype = (std::is_same<T, lace::Set>::value || std::is_same<T, lace::Num>::value);
	
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
		Num(std::string name, lace::prim value);
		lace::prim value;
	};

	class Set : public LaceType
	{
	public:
		Set(std::string name);
		Set(std::string name, std::vector<lace::prim> vec);

		std::vector<lace::prim> data;

	};

	class Expression 
	{
		std::vector<lace::Set> input_sets;
		std::vector<lace::Num> input_nums;

		std::vector<lace::Set*> output_sets;
		std::vector<lace::Num*> output_nums;

		std::string expr_raw;

	public:
		Expression(std::string expr);

		Expression& withInput(lace::Num num);
		Expression& withInput(lace::Set set);

		Expression& withOutput(lace::Num* num);
		Expression& withOutput(lace::Set* set);

		Expression& evaluate();
	};
}
