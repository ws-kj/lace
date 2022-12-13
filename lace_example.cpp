#include "lace.h"

int main(int argc, char** argv)
{
	std::vector<lace::prim> vec{ 1, 2, 3, 4, 5, 6 };
	lace::Set outb = lace::Set("B");
	/*
	lace::Expression expr = lace::Expression(LACE_RAW(
		`let A = { 2, 9, 5, 100, 24, 76 }		
		`let B = { 45, 20, 56, 34, 23, 11, 75 }		
		`let C = A union B							
	
		`let D = {100, 50, 75}						
		
		`let f(X, Y) = do                            
			`{x | x elem (X \\ Y) \\/ abs(x) >= 50 }	
		`end											
													
		`fin = { x | x elem f(C, D) }				
		)).with_output(&outb).evaluate();
		*/

	lace::Expression expr = lace::Expression(LACE_RAW(B = A \\ {2, abs(-4), 6} ))
		.with_input(lace::Set("A", vec))
		.with_output(&outb)
		.evaluate(); 
		
	//std::cout << outb.data[0] << std::endl;
	
	return 0;
}
