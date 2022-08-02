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

	class Num
	{
		std::string name;
		lace::prim value;

	public:
		Num(std::string name, lace::prim value);

		std::string getName();
		double getValue();
	};

	class Set 
	{
		std::string name;
		std::vector<lace::prim> data;

	public:
		Set();
		Set(std::string name, std::vector<lace::prim>& vec);
		
		std::string getName();
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

		template<typename T>
		lace::Expression& withInput(T data) {
			static_assert(lace::is_lacetype<T>);

			if (std::is_same<T, lace::Set>::value)
				this->input_sets.push_back(data);
//			if(typeid(data) == typeid(lace::Num))
//				this->input_nums.push_back(data);


			return *this;
		}

		lace::Result evaluate();
	};
}
