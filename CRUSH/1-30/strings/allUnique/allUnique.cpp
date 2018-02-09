/* Corey Garvey - Jan 30 2018
*	All Unique Characters */

#include <iostream>
#include <cstring>
using namespace std;

bool allUniqueDS(char* s){
	char* alphabet = new char[52];
	// How to initialize array with value
	for(int i=0; i<52; i++){
		alphabet[i] = 0;
	}
	int stringLen = strlen(s);
	for(int i=0; i<stringLen; i++){
		int val = s[i] - 'a';
		cout << "val: " << val << endl;
		cout << "letter " << s[i] << endl;
		if(alphabet[val] > 0) return false;
		alphabet[val]++;
	}
	return true;
}

bool allUniqueNoDS(char* s){
	int stringLen = strlen(s);
	for(int i=0; i<stringLen; i++){
		char letter = s[i];
		for(int j=i+1; j<stringLen; j++){
			if(s[j] == letter){
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char** argv){
	int MAX_LEN = 100;
	char s[MAX_LEN];

	//string s;

	bool allUnique, allUnique2;
	// Test this conditional with < 0, different things
	while(strcmp(s, "exit") != 0){
		cout << "Enter a string (or 'exit' to cancel): " << endl;
		cin.getline(s,MAX_LEN);
		allUnique = allUniqueNoDS(s);
		cout << "This string is ";
		if(!allUnique) cout << "not ";
		cout << "unique." << endl;

	}

	return 0;
}