#include "lace.h"

int main(int argc, char** argv)
{
	std::vector<lace::prim> vec{ 1, 2, 3, 4, 5, 6 };
	lace::Set outb = lace::Set("B");

	lace::Expression expr = lace::Expression("A \\ {2, 4, 6}")
		.withInput(lace::Set("A", vec))
		.withOutput(&outb)
		.evaluate();

	//std::cout << outb.data[0] << std::endl;
	
	return 0;
}
