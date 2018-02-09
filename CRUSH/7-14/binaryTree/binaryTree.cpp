/* Corey Garvey - July 14
 * Binary Tree */

#include <iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* newNode(int value){
    node *newNode = new node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

node* insert(node* thisNode, int value){
    if(thisNode == nullptr){
        return newNode(value);
    }
    if(value <= thisNode->data){
        thisNode->left = insert(thisNode->left, value);
    } else{
        thisNode->right = insert(thisNode->right, value);
    }
    return thisNode;
}

bool lookup(node* thisNode, int value){
    if(thisNode == nullptr){
        return false;
    }
    if(thisNode->data == value){
        return true;
    }
    if(value < thisNode->data){
        return lookup(thisNode->left, value);
    } else {
        return lookup(thisNode->right, value);
    }
}

int size(node* thisNode){
    int counter = 0;
    if(thisNode == nullptr) return 0;
    counter++;
    counter += size(thisNode->left);
    counter += size(thisNode->right);
    return counter;
}

int minValue(node* thisNode){
    if(thisNode == nullptr) return -1;
    if(thisNode->left == nullptr) return thisNode->data;
    return minValue(thisNode->left);
}

void printPreOrder(node* thisNode){
    cout << thisNode->data << " ";
    if(thisNode->left != nullptr){
        printPreOrder(thisNode->left);
    }
    if(thisNode->right != nullptr){
        printPreOrder(thisNode->right);
    }
    return;
}

void printInOrder(node* thisNode){
    // Print left
    if(thisNode->left != nullptr){
        printInOrder(thisNode->left);
    }
    cout << thisNode->data << " ";
    // Print right
    if(thisNode->right != nullptr){
        printInOrder(thisNode->right);
    }
}

void printPostOrder(node* thisNode){
    if(thisNode->left != nullptr){
        printPostOrder(thisNode->left);
    }
    if(thisNode->right != nullptr){
        printPostOrder(thisNode->right);
    }
    cout << thisNode->data << " ";
    
}

int main(int argc, char** argv){
    node *myNode = newNode(5);
    insert(myNode, 3);
    insert(myNode, 8);
    insert(myNode, 6);
    insert(myNode, 9);
    insert(myNode, 1);
    insert(myNode, 4);
    insert(myNode, 2);
    insert(myNode, 7);
    cout << lookup(myNode, 3) << endl;
    cout << size(myNode) << endl;
    cout << minValue(myNode) << endl;
    printPreOrder(myNode);
    cout << endl;
    printInOrder(myNode);
    cout << endl;
    printPostOrder(myNode);
    cout << endl;

    return 0;
}
