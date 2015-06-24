#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Node {
public:

    Node(int value, Node* left, Node* right):
        value(value), left(left), right(right){
    }
    int value;
    Node* left;
    Node* right;
};

class BST {
public:

    // Checks if a binary tree is a binary search tree.
    bool isBST(Node* root) {
        return treeInRange(root);
    }

private:
    bool treeInRange(Node* root, int lower = INT_MIN, int higher = INT_MAX){

        if (root == NULL){
            return true;
        }
        else if(root->value >= higher || root->value < lower){
            return false;
        } else {
            return(treeInRange(root->left, lower, root->value) && treeInRange(root->right, root->value, higher));
        }

    }


};

int main(){

/*
    //   DEPTH:  0        1        2        3
    Node* node = new Node(10,
                          new Node(5,
                                   new Node(3,
                                            NULL,
                                            NULL),
                                   new Node(7,
                                            NULL,
                                            NULL)),
                          new Node(15,
                                   new Node(12,
                                            NULL,
                                            NULL),
                                   new Node(20,
                                            NULL,
                                            NULL)));

    BST bst;
    cout << bst.isBST(node);
*/

    return 0;
}














