// This is in no way actual code, this is just to have a backend version of these function to be easily implemented instead of doing it from scratch last minute.

// THE ELEM STATEMENT
/*
A elem B (is how it would be called)
Assuming A is a properly declared datatype and B is a properly declared vector filled with datatypes that match A
Not taking namespaces into account
*/
bool elem = false;
for (auto elem: B){
	if (elem == A){
		elem = true;
	}
}
return elem;
