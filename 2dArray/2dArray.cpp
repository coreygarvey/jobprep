/* Corey Garvey - July 11
 * 2D Arrays */
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    
    int ROWS = 3;
    int COLS = 5;

    int twoD[ROWS][COLS];
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            twoD[i][j] = i*COLS+j;
        }
    }
    
    cout << "Here's the array: " << endl;
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            cout << "twoD[" << i << "][" << j
                << "]: " << twoD[i][j] << endl;
        }
    }
    

    return 0;
}
