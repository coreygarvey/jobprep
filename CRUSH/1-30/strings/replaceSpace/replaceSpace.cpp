/* Corey Garvey - Jan 30 2018
*	Replace Strings */

#include <iostream>
#include <cstring>

using namespace std;

char* replaceSpaces(char* s){
	int sLen = strlen(s);
	// Count spaces
	int spaces=0;
	for(int i=0; i<sLen; i++){
		if(s[i] == ' ') ++spaces;
	}
	// Add 2 chars per space: ' ' to '%20'
	int newLen = sLen + 2*spaces;
	char* r = new char[newLen];
	// Iterate through s, filling in r with appropriate chars
	int j=0;
	for(int i=0; i<sLen; i++){
		if(s[i] == ' ') {
			r[j] = '%';
			r[j+1] = '2';
			r[j+2] = '0';
			j += 2;
		} else {
			r[j] = s[i];
		}
		j++;
	}
	return r;
}

int main(int argc, char** argv){
	int MAX_LENGTH = 100;
	char s[MAX_LENGTH];
	cout << "Enter your string (or 'exit'): " << endl;
	cin.getline(s, MAX_LENGTH);
	char* r;
	while(strcmp(s, "exit") != 0){
		
		cout << "Original: " << s << endl;
		r = replaceSpaces(s);
		cout << "Replaced: " << r << endl;
		
		cout << "Enter your string (or 'exit'): " << endl;
		cin.getline(s, MAX_LENGTH);		
	}

	return 0;
}