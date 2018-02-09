/* Corey Garvey - Jan 30 2018
*	Remove Dups using C-style string */
#include <iostream>
#include <cstring>
using namespace std;

void removeDupsNoDS(char* s){
	int sLen = strlen(s);
	
	if(sLen <= 1){
		return;
	}

	int tail = 1;
	for(int i=1; i<sLen; i++){
		int j;
		for(j=0; j<tail; j++){
			if(s[i] == s[j]){ break; }
		}
		if(j == tail){
			s[tail] = s[i];
			++tail;
		}
	}
	
	s[tail] = '\0';
	
	return;
}

void removeDupsDS(char* s){
	
	int sLen = strlen(s);
	if(sLen <= 1){
		return;
	}
	bool letters[256];
	for(int i=0; i<256; i++){
		letters[i] = false;
	}
	// Mark first letter
	letters[s[0]]=true;
	int tail = 1;
	for(int i=1; i<sLen; i++){
		// check if letter has occurred
		if(letters[s[i]]==false){
			letters[s[i]]=true;
			s[tail] = s[i];
			++tail;
		}
	}
	cout << "tail: " << tail << endl;
	s[tail] = '\0';
	return;
}

int main(int argc, char** argv){
	int MAX_SIZE = 100;
	char s[MAX_SIZE];

	cout << "Enter a string (or 'exit' to quit)" << endl;
	cin.getline(s,MAX_SIZE);

	while(strcmp(s,"exit") != 0){
		cout << "Your string: " << endl;
		cout << s << endl;
		
		removeDupsDS(s);

		cout << "Dups removed: " << endl;
		cout << s << endl;

		cout << "Enter a string (or 'exit' to quit)" << endl;
		cin >> s;
	}

	return 0;
}
