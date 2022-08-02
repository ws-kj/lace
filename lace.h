#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <optional>

namespace lace 
{
	template <typename T>
	constexpr bool is_lacetype = (std::is_same<T, lace::Set>::value || std::is_same<T, lace::Num>::value);
	
	typedef double Num;

	class Set 
	{
		std::string name;
		std::vector<lace::Num> data;

	public:
		Set();
		Set(std::vector<lace::Num>& vec);
		Set(std::string name);
		Set(std::vector<lace::Num>& vec, std::string name);
		
		std::string getName();
		std::vector<lace::Num> asVec();
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

	template<typename... Args>
	lace::Result EvalWith(std::string expr, Args... dat);
}