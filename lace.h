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
		lace::prim value;

	public:
		Num(std::string name, lace::prim value);

		lace::prim getValue();
	};

	class Set : public LaceType
	{
		std::vector<lace::prim> data;

	public:
		Set();
		Set(std::string name, std::vector<lace::prim>& vec);
		
		std::vector<lace::prim> asVec();
	};

	class Result 
	{
		lace::Set data;
		std::string err;

	public:
		Result(lace::Set data);
		Result(lace::Set data, std::string err);

		std::optional<lace::Set> getData();
		std::string getError();
	};

	class Expression 
	{
		std::vector<lace::Set> input_sets;
		std::vector<lace::Num> input_nums;

		std::string expr_raw;

	public:
		Expression(std::string expr);

		Expression& withInput(lace::Num num);
		Expression& withInput(lace::Set set);

		lace::Result evaluate();
	};
}
