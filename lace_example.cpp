#include "lace.h"

int main(int argc, char** argv)
{

	/*
		Goal: Eval this expression and return the right answer.

		lace::Result set_diff(std::vector<lace::Num> my_vec)
		{
			auto A = lace::Set(&my_vec, �A�);
			return lace::EvalWith<lace::Set>(�A \ {2, 4, 6}�, &A);
		}

		std::vector<lace::Num> vec{1, 2, 3, 4, 5, 6};
		cout << set_diff(vec).getData().asVec().size() << endl; //Expect 3

	*/
	std::vector<lace::prim> vec{ 1, 2, 3, 4, 5, 6 };
	lace::Set outb = lace::Set("B");

	lace::Expression("A \\ {2, 4, 6}")
		.withInput(lace::Set("A", vec))
		.withOutput(&outb)
		.evaluate();

	std::cout << outb.data[0] << std::endl;
	
	return 0;
}
