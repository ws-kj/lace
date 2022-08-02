#include <vector>
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

// THE SUBSET STATEMENT
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

	return final; // will return true if the set of elements in A but not B is empty, and the set of elements in B but not A is not empty
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
