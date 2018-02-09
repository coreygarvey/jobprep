/* Corey Garvey - Jan 30 2018
* 	Reverse C-Style String */
#include <iostream>
#include <cstring>
using namespace std;


char* reverseString(char* s){
	int stringLen = strlen(s);
	cout << "s: " << s << endl;
	cout << "stringLen: " << stringLen <<endl;
	char *r = new char[stringLen];
	for(int i=stringLen-1; i>=0; i--){
		r[stringLen-i-1] = s[i];
	}
	r[stringLen] = '\0';
	cout << "r: " << r << endl;
	return r;
}

void reverse(char* s){
	// Two pointers at the same object
	char* end = s;
	char tmp;
	if(s){
		// Iterate to \0 of end
		while(*end){
			++end;
		}
		// Move to final character
		--end;
		// As they converge in middle, swap characters
		while(s < end){
			// Store front char
			tmp = *s;
			// Set front to end and iterate
			*s++ = *end;
			// Set end to front and iterate
			*end-- = tmp;
		}
		// Both s and end are now at middle
	}
}


int main(int argc, char** argv){
	int MAX_SIZE = 100;
	char s[MAX_SIZE];
	//char r[MAX_SIZE];  useful if passing pointer to r into reverse function
	cout << "Please enter a string (or 'exit' to quit')" << endl;
	cin.getline(s,MAX_SIZE);
	while(strcmp(s, "exit") != 0){
		//char* r = reverseString(s);
		char* r = reverseString(s);
		cout << "Your string: " << s << endl;
		//reverse(s);
		cout << "Reversed: " << r << endl;
		cout << "Please enter a string (or 'exit' to quit')" << endl;
		cin.getline(s,MAX_SIZE);
	}


	return 0;
}