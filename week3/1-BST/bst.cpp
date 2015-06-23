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

        if (root == NULL){
            return true;
        }

        if(root->left != NULL){
            if(root->left->value > root->value){
                return false;
            }
        }
        if(root->right != NULL){
            if(root->right->value < root->value){
                return false;
            }
        }

        return (isBST(root->left) && isBST(root->right));

    }
};

int main(){

/*    // DEPTH:  0        1        2        3
    Node* node = new Node(10,
                          new Node(5,
                                   new Node(3,
                                            NULL,
                                            NULL),
                                   new Node(7,
                                            NULL,
                                            NULL)),
                          new Node(15,
                                   NULL,
                                   new Node(20,
                                            NULL,
                                            NULL)));

    BST bst;
    cout << bst.isBST(node);
*/

    return 0;
}














