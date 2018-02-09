/* Corey Garvey - Feb 5 2018
*	Three stacks - One Array */

#include <iostream>

using namespace std;

class tripleStack{
public:
	void push(int stack, int val){
		if(indexes[stack]>=stackSize){
			cout << "Stack's full" << endl;
			return;
		}
		indexes[stack]++;
		int arrayIndex = stack * stackSize + indexes[stack];
		
		storage[arrayIndex] = val;
		return;
	}
	int pop(int stack){
		if(indexes[stack] == 0){
			cout << "Stack's empty" << endl;
			return -1;
		}
		int returnVal = storage[indexes[stack]];
		//storage[indexes[stack]] = NULL;
		indexes[stack]--;
		return returnVal;
	}
	int peek(int stack){
		if(indexes[stack] == 0){
			cout << "Stack's empty" << endl;
			return -1;
		}
		int returnVal = storage[indexes[stack]];
		return returnVal;	
	}
	tripleStack(int size){
		stackSize = size;
		storage = new int[size*3];
		for(int i=0; i<3; i++) indexes[i]=0;
	}
private:
	int stackSize;
	int indexes[3];
	int *storage;
};



int main(){
	tripleStack* myStacks = new tripleStack(100);
	for(int i=0; i<35; i++){
		myStacks->push(0,i);
	}
	cout << myStacks->pop(0) << endl;
	cout << myStacks->peek(0) << endl;
	cout << myStacks->pop(0) << endl;
	
	return 0;
}