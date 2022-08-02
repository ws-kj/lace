#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace lace 
{
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

	template<class T>
	class Result {

	};
}