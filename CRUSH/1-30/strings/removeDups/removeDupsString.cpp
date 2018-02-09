/* Corey Garvey - Jan 30 2018
*	Remove Dups using std::string */

#include <iostream>
using namespace std;

string removeDupsNoDS(string s){
	int sLen = s.length();
	
	if(sLen <= 1){
		return s;
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
	
	s.resize(tail);
	
	
	return s;
}


string removeDupsDS(string s){
	
	int sLen = s.length();

	if(sLen <= 1){
		return s;
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
		
		if(letters[s[i]]==true){
			break;
		} else{
			letters[s[i]]=true;
			s[tail] = s[i];
			++tail;
		}
	}
	s.resize(tail)
	return s;
}

int main(int argc, char** argv){
	string s;

	cout << "Enter a string (or 'exit' to quit)" << endl;
	cin >> s;

	while(s != "exit"){
		cout << "Your string: " << endl;
		cout << s << endl;
		s = removeDupsNoDS2(s);

		cout << "Dups removed: " << endl;
		cout << s << endl;

		cout << "Enter a string (or 'exit' to quit)" << endl;
		cin >> s;
	}

	return 0;
}
