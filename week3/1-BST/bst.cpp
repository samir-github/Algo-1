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

    bool arr_is_bst(int tree[100000], int root, int size, int lower = INT_MIN, int higher = INT_MAX){

        if(root > size || tree[root] == 0) return true;
        if(tree[root] <= lower || tree[root] >= higher) return false;
        return(arr_is_bst(tree, root*2+1, size, lower, tree[root]) && arr_is_bst(tree, root*2+2, size, tree[root], higher));
    }

    bool isBST(Node* root) {
        return treeInRange(root);
    }

private:



    bool treeInRange(Node root[], int lower = INT_MIN, int higher = INT_MAX){

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


    int n, tmp;
    int tree[100000];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        tree[i] = tmp;
    }

    BST bst_tester;

    if(bst_tester.arr_is_bst(tree, 0,  n)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }









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














