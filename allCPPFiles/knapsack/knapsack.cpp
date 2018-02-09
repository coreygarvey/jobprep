/* Corey Garvey - Jan 28 2018
* Knapsack Problem */

#include <iostream>

using namespace std;


int max(int a, int b){
	return (a > b) ? a : b;
}

int knap(int W, int* wt, int* vals, int n){
	int maxVals[n+1][W+1];

	for(int i=0; i<=n; i++){
		for(int w=0; w<=W; w++){

			if(i==0 || w==0){
				maxVals[i][w] = 0;
			} else if(wt[i-1] <= w){
				maxVals[i][w] = max(vals[i-1] + maxVals[i-1][w-wt[i-1]], maxVals[i-1][w]);
			} else{
				maxVals[i][w] = maxVals[i-1][w];
			}
		}
	}
	return maxVals[n][W];


}


int main(int argc, char** argv){
	int W = 50;
	int wt[] = {10, 20, 30};
	int vals[] = {60, 100, 120};

	// Length of the wt list
	int n = sizeof(wt)/sizeof(*wt);

	// Return maximum weight based on inputs
	int maxWeight = knap(W, wt, vals, n);

	cout << "max weight: " << maxWeight << endl;

	return 0;
}