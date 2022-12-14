
#include <vector>
#include <iostream>
#include <string>
using namespace std;
// This is in no way actual code, this is just to have a backend version of these function to be easily implemented instead of doing it from scratch last minute.

// THE ELEM STATEMENT
/*
A elem B (is how it would be called)
Assuming A is a properly declared datatype and B is a properly declared vector filled with datatypes that match A
Not taking namespaces into account
add std in before vector

*/
template <class T> 
bool elem(vector<T> A, vector<T> B){
	bool elem = false;
	for (T element: B){
		if (element == A){
			elem = true;
		}
	}
	return elem;
}


 
// THE PROPER SUBSET STATEMENT
/*
A psubset B (is how it would be called)
Assuming A is a properly declared vector and B is a properly declared vector filled with datatypes that match A
Not taking namespaces into account
add std in before vector
*/
template <class T> 
bool psubset(vector<T> A, vector<T> B){
	vector<T> vect_inA_notB;

	for(T element: A){
		bool found = false;
		for(T element2: B){
			if(element==element2){
				found = true;
			}
		}
		if(!found){
			vect_inA_notB.push_back(element);
		}
	}
	bool empty = vect_inA_notB.size() == 0;
	if(empty==false){
		return false;
	}

	vector<T> vect_inB_notA;
	for(T element: B){
		bool found = false;
		for(T element2: A){
			if(element==element2){
				found = true;
			}
		}
		if(!found){
			vect_inB_notA.push_back(element);
		}
	}
	bool empty2 = vect_inB_notA.size() != 0;
	if(empty2==false){
		return false;
	}

	return final; // will return true if the set of elements in A but not B is empty, and the set of elements in B but not A is not empty.  COULD IMPLEMENT DIFFERENCES CALL?
}


// THE  SUBSET STATEMENT
/*
A subset B (is how it would be called)
Assuming A is a properly declared vector and B is a properly declared vector filled with datatypes that match A
Not taking namespaces into account
add std in before vector
*/
template <class T> 
bool subset(vector<T> A, vector<T> B){
	vector<T> vect_inA_notB;

	for(T element: A){
		bool found = false;
		for(T element2: B){
			if(element==element2){
				found = true;
			}
		}
		if(!found){
			vect_inA_notB.push_back(element);
		}
	}
	bool empty = vect_inA_notB.size() == 0;
	if(empty==false){
		return false;
	}



	return empty; // will return true if the set of elements in A but not B is empty  COULD IMPLEMENT DIFFERENCES CALL?
}


//is_empty_set() call
/*
Assuming A is a properly declared vector 
Returning a boolean on if a set is equivalent to the empty set
add std in before vector
*/
template <class T> 
bool is_empty_set(vector<T> A){
	bool empty = A.size()==0;
	return empty;
	// If we really wanted to get complicated and computationally stupid we could check to see what the difference is for each and see if it is both 0 but we aren't that dumb ;)
}




// THE DIFFERENCE OPERATION
/*
A \ B
Assuming A is a properly declared vector and B is a properly declared vector filled with datatypes that match A
Returns a vector of elements in A that are not in B
add std in before vector
*/
template <class T> 
vector<T> difference(vector<T> A, vector<T> B){
	vector<T> vect_inA_notB;
	for(T element: A){
		bool found = false;
		for(T element2: B){
			if(element==element2){
				found = true;
			}
		}
		if(!found){

			vect_inA_notB.push_back(element);
		}
	}
	return vect_inA_notB;
}


// THE UNION STATEMENT
/*
A union B (is how it would be called)
Assuming A is a properly declared vector and B is a properly declared vector filled with datatypes that match A
Not taking namespaces into account
add std in before vector
UNION is a protected keyword
returns a + b
*/
template <class T> 
vector<T> unions(vector<T> A, vector<T> B){
	vector<T> both_combined;
	for(T elem: A){
		both_combined.push_back(elem);
	}
	for(T elem: B){
		both_combined.push_back(elem);
	}

	return both_combined;
}



// THE INTER STATEMENT
/*
A inter B (is how it would be called)
Assuming A is a properly declared vector and B is a properly declared vector filled with datatypes that match A
Not taking namespaces into account
add std in before vector
returns the shared values of a and b 
*/
template <class T> 
vector<T> inter(vector<T> A, vector<T> B){
	vector<T> vect_in_both;
	for(T element: A){
		bool found = false;
		for(T element2: B){
			if(element==element2){
				found = true;
			}
		}
		if(found){

			vect_in_both.push_back(element);
		}
	}
	return vect_in_both;
}


// THE FACTORIAL OPERATION
/*
x!
Assuming x is a properly declared int
not using namespaces
returns x factorial
*/
long long int factorial(int x){
	long long int total = 1;  // I'm planning for BIG numbers even though this is like supercomputer size
	if(x>0){
		while(x>0){
			total*=x;
			x--;
		}
	}
	else if(x<0){
		total = -1;
	}
	return total;
}


// THE abs function
/*
abs(x)
assuming x is a properly declared integer or double
not using namespace
returns abs value of x
going to do it differently than c++
I'm gonna write this function as poorly as possible, I'll change it later to the commented code to make it more efficient
*/
template <class T>
T abs(T x){
	if(x > 0){
		continue;
	}
	else if(x == 0){
		continue;
	}
	else if(x < 0){
		x *= -1;
	}
	/*
	if(x<0){
		x*=-1;
	}
	*/
	return x;
}

// THE SAME FUNCTION
/*
lace::the_same(a, b);
assuming a is a properly declared vector and b is a properly declared vector of the same type as a
not using namespace
returns true if sets are the same or false if different
*/

template <class T>
bool the_same(vector<T> A, vector<T> B){
	vector<T> inA_maybeB = difference(A, B);
	vector<T> inB_maybeA = difference(B, A);
	if(inB_maybeA.size()!=0 || inA_maybeB.size()!=0){
		return false;
	}
	else{
		return true;
	}
}


// EMPTY SET
/*
generates and returns the empty set
not using namespace
*/
template <class T>
vector<T> empty_set(){
	vector<T> empty;
	return empty;
}

int main(){
	return 0;
}