/* Corey Garvey - July 25
 * Binary Tree */
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* tmp = new Node;
    tmp->data = val;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}

class BinaryTree{
    public:
        Node* root;
        BinaryTree(int initVal){
            Node* tmp = newNode(initVal);
            root = tmp;
        }
        Node* insert(Node* node, int val){
            if(node == nullptr){
                return newNode(val);
                
            }
            if(val <= node->data){
                node->left = insert(node->left, val);
            } else {
                node->right = insert(node->right, val);
            }
            return node;
        }

        int size(Node* node){
            int size = 0;
            if(node == nullptr){
                return size;
            }
            size++;
            size += this->size(node->left);
            size += this->size(node->right);
            return size;
        }

        int minValue(Node* node){
            if(node->left == nullptr){
                return node->data;
            }
            return this->minValue(node->left);
        }
        
        bool lookup(Node* node, int val){
            if(node == nullptr){
                cout << "Sorry, not in this BT" << endl;
                return false;
            }
            if(node->data == val){
                cout << "Found it!" << endl;
                return true;
            }
            if(val < node->data){
                return this->lookup(node->left, val);
            } else{
                return this->lookup(node->right, val);
            }
        }

        void printPreOrder(Node* node){
            if(node != nullptr){
                cout << node->data << " ";
            }
            if(node->left != nullptr){
                printPreOrder(node->left);
            }
            if(node->right != nullptr){
                printPreOrder(node->right);
            }
            return;
        }
        
        void printInOrder(Node* node){
            if(node->left != nullptr){
                printInOrder(node->left);
            }
            if(node != nullptr){
                cout << node->data << " ";
            }
            if(node->right != nullptr){
                printInOrder(node->right);
            }
            return;
        }
        void printPostOrder(Node* node){
            if(node->left != nullptr){
                this->printPostOrder(node->left);
            }
            if(node->right != nullptr){
                this->printPostOrder(node->right);
            }
            cout << node->data << " ";
        }

};

BinaryTree* build123(){
    BinaryTree* myBT = new BinaryTree(2);
    myBT->insert(myBT->root, 1);
    myBT->insert(myBT->root, 3);
    return myBT;
}

int main(int argc, char** argv){
    BinaryTree* my123 = build123();
    cout << "Size: " << my123->size(my123->root) << endl;


    BinaryTree* my6 = new BinaryTree(5);
    my6->insert(my6->root,3);
    my6->insert(my6->root,7);
    my6->insert(my6->root,2);
    my6->insert(my6->root,8);
    my6->insert(my6->root,1);
    my6->insert(my6->root,6);
    my6->insert(my6->root,4);
    my6->insert(my6->root,10);
    my6->printPreOrder(my6->root);
    cout << endl;
    my6->printInOrder(my6->root);
    cout << endl;
    my6->printPostOrder(my6->root);
    cout << endl;
    cout << "Size: " << my6->size(my6->root) << endl;
}

