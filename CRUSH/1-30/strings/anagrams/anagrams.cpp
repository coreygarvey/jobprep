/* Corey Garvey - Jan 30 2018
*	Anagrams? */

#include <iostream>
#include <cstring>
using namespace std;


bool anagrams(char* f, char* s){
	int fLen = strlen(f);
	int sLen = strlen(s);
	if(fLen != sLen) return false;

	int sum=0;
	int letter_count[26];
	for(int i=0; i<26; i++){
		letter_count[i] = 0;
	}

	// fill letter count
	for(int i=0; i<fLen; i++){
		letter_count[f[i]-'a']++;
	}

	// run through second string (s), decreasing counts
	for(int i=0; i<sLen; i++){
		if(letter_count[s[i]-'a']<1) return false;
		letter_count[s[i]-'a']--;
	}
	return true;
}

int main(int argc, char** argv){

	char first[] = "phone";
	char second[] = "eonph";
	char third[] = "corey";

	bool firstTest = anagrams(first, second);
	cout << "First test: " << firstTest << endl;
	bool secondTest = anagrams(first, third);
	cout << "Second test: " << secondTest << endl;



	return 0;
}