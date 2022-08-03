#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <optional>


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
		std::string get_name();
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

		Expression& with_input(Num num);
		Expression& with_input(Set set);

		Expression& with_output(Num* num);
		Expression& with_output(Set* set);

		Expression& evaluate();
	};
}
