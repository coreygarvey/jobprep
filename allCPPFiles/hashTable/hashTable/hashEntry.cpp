/* Corey Garvey - July 5
 * Hash Table - Entry */

#include "hashEntry.h"

HashEntry::HashEntry(int key, int value){
    this->key = key;
    this->value = value;
}

int HashEntry::getKey(){
    return key;
}

int HashEntry::getValue(){
    return value;
}
