/* Corey Garvey - July 6
 * Cracking - 1.2
 * Reverse a C-Style String */

#include <iostream>
using namespace std;

void reverseString(char corey[]){
    cout << corey << endl;
    char *corey_ptr = corey;
    char *end = corey_ptr;
    
    char tmp;
    // Put pointer at final char
    while(*end){
       end++;
    }
    // Because of null char, must move back 1
    end--;
    // While the front ptr still in front, swap and move
    while(corey_ptr < end){
        //cout << corey_ptr << endl;
        //cout << end << endl;
        tmp = *corey_ptr;
        *corey_ptr = *end;
        *end = tmp;
        end--;
        corey_ptr++;
    }
    cout << corey << endl;
};


int main() {
    char corey[] = "Corey";
    reverseString(corey);
    return 0;
};
