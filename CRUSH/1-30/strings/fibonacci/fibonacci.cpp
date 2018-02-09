/* Corey Garvey - Jan 30 2018
*	Fibonacci Series */

#include <iostream>
using namespace std;

int fib(int val){
	int s;
	if(val == 0){
		s = 0;
	}
	if(val == 1){
		s = 1;
	}
	if(val > 1){
		s = fib(val-1) + fib(val-2);
	}
	if(val < 0){
		s = -1;
	}
	return s;
}


int main(int argc, char** argv){
	int val = 1;
	int fibonacci;
	while(val > 0){
		cout << "Enter a number to learn Fibonacci (or 0 to exit):" << endl;
		cin >> val;

		fibonacci = fib(val);

		cout << "Fibonacci number is: " << fibonacci << endl;
		
	}

	return 0;
}