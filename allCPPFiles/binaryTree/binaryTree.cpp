/* Corey Garvey - July 19 
 * Binary Tree */
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* thisNode = new Node;
    thisNode->data = val;
    thisNode->left = nullptr;
    thisNode->right = nullptr;
    return thisNode;
};

class BinaryTree{
    public:
        Node* root;
        BinaryTree(int val){
            Node* rootNode = newNode(val);
            root = rootNode;
        }
        Node* insert(int val, Node* node){
            if(node == nullptr){
                return newNode(val);
            }
            if(val < node->data){
                node->left = this->insert(val, node->left);
                return node->left;
            } else {
                node->right = this->insert(val, node->right);
                return node->right;
            }
        }
        bool lookup(int val, Node* node){
            if(node == nullptr){
                cout <<"Not found" << endl;
                return false;
            }
            if(node->data == val){
                cout << "Found" << endl;
                return true;
            }
            if(val < node->data){
                return this->lookup(val, node->left);
            }
            else {
                return this->lookup(val, node->right);
            }
        }
        int size(Node* node){
            if(node==nullptr){
                return 0;
            }
            int size = 1;
            size += this->size(node->left);
            size += this->size(node->right);
            return size;
        }
        int minValue(){
            Node* currNode = root;
            while(currNode->left != nullptr){
                currNode = currNode->left;
            }
            return currNode->data;
        }
};
BinaryTree* build123(){
    BinaryTree* bt = new BinaryTree(2);
    Node* btRoot = bt->root;
    bt->insert(1, btRoot);
    bt->insert(3, btRoot);
    return bt;
}

int main(int argc, char** argv){
    BinaryTree* bt = build123();
    cout << "Size: " << bt->size(bt->root) << endl;
}
