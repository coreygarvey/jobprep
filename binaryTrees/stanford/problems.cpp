/* Corey Garvey - July 8
 * Build Binary Trees 3 ways */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

// Boolean lookup function
int lookup(node *node, int target){
    // Base case, empty tree
    if(node == nullptr){
        return false;
    } else {
        if(node->data == target){
            return true;
        }else{
            if(lookup(node->left, target)) return true;
            else{
                return lookup(node->right, target);
            }
        }
    }
}

node* newNode(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

node* insert(node* node, int data){
    if(node == nullptr){
        return newNode(data);
    } else {
        if(data <= node->data){
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
};

// 1. build123()
// build123a: call newNode() 3 times, using 3 pointer var
node* build123a(){
    node* one = newNode(1);
    node* two = newNode(2);
    node* three = newNode(3);
    node* root = two;
    root->left = one;
    root->right = three;
    return root;
}

// build123b: call newNode() 3 times, using 1 pointer var
node* build123b(){
    node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    return root;
};

// build 123c: call insert() three times 
//  passing it the root pointer to build 
//  up the tree
node* build123c(){
    node* root = nullptr;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    return root;
};

// build12345()
node* build12345(){
    node* root = nullptr;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 3);
    //root = insert(root, 7);
    return root;
};

// 2. size()
//  Given a binary tree, count the number of nodes
int size(node* node){
    int value = 0;
    if(node == nullptr){
        return 0;
    }
    value = 1 + size(node->left) + size(node->right);
    return value;
}

// 3. maxDepth();
//  Given a binary tree, compute its "maxDepth" from root
int maxDepth(struct node* node){
    int depth = 0;
    if(node == nullptr){
        return depth;
    }
    // Current node
    depth++;
    // Add longest path
    depth += max(maxDepth(node->left), maxDepth(node->right));
    return depth;
}

// 4. minValue()
//  Return minimum data value found in binary search tree
//  Not necessary to search entire tree
int minValue(struct node* node) {
    int value = node->data;
    if(node->left != nullptr){
       value = minValue(node->left);
    }
    return value;
}

// 5. printTree()
//  Given a BST - iterate over nodes to print in increasing order
//  recur left, print data, recur right
void printTree(node* node){
    if(node == nullptr) return;
    printTree(node->left);
    cout << node->data << " ";
    printTree(node->right);
}

// 6. print Postorder()
//  Given binary tree, print according to bottom up, "postorder"
//  traversal. Both subtrees printed completely before node printed.
//  Each left printed before right.
void printPostorder(node* node){
    if(node == nullptr) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

// 7. hasPathSum()
//  Given binary tree and sum, return true if tree has root-to-leaf
//  path such that adding up all values equals given sum.
//  Return false if no path can be found
int hasPathSum(node*node, int sum){
    if(node == nullptr) return 0;
    int count = 0;
    int current_val = node->data;
    sum -= current_val;
    if(node->left == nullptr && 
            node->right == nullptr) {
        if(sum==0){
            return 1;
        } else{
            return 0;
        }
    }
    else {
        count += hasPathSum(node->left, sum);
        count += hasPathSum(node->right, sum);
    }
    return count; 
}

// 8. printPaths()
//  Given binary tree, print out all root-to-leaf paths.
//  "paths so far" must be communicated between recursive calls
void printPath(int path[], int pathLen){
    for(int i=0; i<pathLen; i++){
        cout << path[i];
        if(i < pathLen-1){
            cout << "-";
        }
    }
    cout << endl;
    return;
}

void printPathsRecur(node* node, int path[], int pathLen){
    if(node == nullptr) return;
    // Add this node to the path
    path[pathLen] = node->data;
    pathLen++;
    // If leaf print, othewise check again
    if(node->left == nullptr && node->right == nullptr){
        printPath(path, pathLen);
        return;
    }
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen); 
    return;
}

void printPaths(node* node){
    int path[1000];
    printPathsRecur(node, path, 0);
}


int main(int argc, char **argv){
    cout << "Problem 1 - build123()" << endl;

    node* bst123a = build123a();
    cout << bst123a->data << endl;

    node* bst123b = build123b();
    cout << bst123b->data << endl;

    node* bst123c = build123c();
    cout << bst123c->data << endl;

    cout << endl;
    cout << "Problem 2 - size()" << endl;
    int treeSize = size(bst123a);
    cout << "Size: " << treeSize << endl;

    cout << "build12345(): " << endl;
    node* bst12345 = build12345();
    cout << bst12345->data << endl;

    cout << endl;
    cout << "Problem 3 - maxDepth()" << endl;
    int depth = maxDepth(bst12345);
    cout << "maxDepth: " << depth << endl;    
    
    cout << endl;
    cout << "Problem 4 - minValue()" << endl;
    int minVal = minValue(bst12345);
    cout << "minValue: " << minVal << endl;

    cout << endl;
    cout << "Problem 5 - printTree()" << endl;
    printTree(bst12345);
    cout << endl;
    
    cout << endl;
    cout << "Problem 6 - printPostorder()" << endl;
    cout << "printPostorder: ";
    printPostorder(bst12345);
    cout << endl;

    cout << endl;
    cout << "Problem 7 - hasPathSum()" << endl;
    int pathSumCount = hasPathSum(bst12345,14);
    cout << "hasPathSum: " << pathSumCount << endl; 
    
    cout << endl;
    cout << "Problem 8 - printPaths()" << endl;
    printPaths(bst12345);

    return 0;
}




