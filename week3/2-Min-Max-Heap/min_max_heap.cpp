#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
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

class MinMaxHeap {
public:


    bool arr_isMinMaxHeap(int tree[100000], int root, int size, int lower = INT_MIN, int higher = INT_MAX, bool min_level = true){

        if(root >= size) return true;
        if(tree[root] < lower || tree[root] > higher) return false;
        if(min_level){
            return(arr_isMinMaxHeap(tree, root*2+1, size,  tree[root], higher, false) && arr_isMinMaxHeap(tree, root*2+2, size, tree[root], higher, false) );
        } else {
            return(arr_isMinMaxHeap(tree, root*2+1, size, lower, tree[root], true)    && arr_isMinMaxHeap(tree, root*2+2, size, lower, tree[root], true) );
        }

    }


    // Checks if a binary tree is a min/max heap.
    bool isMinMax(Node* root) {

        // Check if its complete tree
        queue<Node*> node_que;
        node_que.push(root);

        while(!node_que.empty()){

            static int elements_at_level = 1;
            static bool null_child_found = false;

            for(int i = 0; i < elements_at_level; i++) {

                if(node_que.front()->left == NULL) {
                    null_child_found = true;
                } else {
                    if(null_child_found){
                        return false;
                    } else {
                        node_que.push(node_que.front()->left);
                    }
                }

                if(node_que.front()->right == NULL){
                    null_child_found = true;
                } else {
                    if(null_child_found){
                        return false;
                    } else {
                        node_que.push(node_que.front()->right);
                    }
                }
                node_que.pop();
            }
        }

        // Check if its Min / Max heap
        queue<Node*> min_queue;
        queue<Node*> max_queue;

        min_queue.push(root);

        while(!min_queue.empty()) {

            if(min_queue.front()->left != NULL) {
                if(min_queue.front()->value > min_queue.front()->left->value) {
                    return false;
                } else {
                    max_queue.push(min_queue.front()->left);
                }
            }
            if(min_queue.front()->right != NULL) {
                if(min_queue.front()->value > min_queue.front()->right->value) {
                    return false;
                } else {
                    max_queue.push(min_queue.front()->right);
                }
            }

            min_queue.pop();

            while(!max_queue.empty()) {

                if(max_queue.front()->left != NULL) {
                    if(max_queue.front()->value < max_queue.front()->left->value) {
                        return false;
                    } else {
                        min_queue.push(max_queue.front()->left);
                    }
                }
                if(max_queue.front()->right != NULL) {
                    if(max_queue.front()->value < max_queue.front()->right->value) {
                        return false;
                    } else {
                        min_queue.push(max_queue.front()->right);
                    }
                }
                max_queue.pop();
            }
        }
        return true;
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

    MinMaxHeap min_max_heap_tester;
    if(min_max_heap_tester.arr_isMinMaxHeap(tree, 0, n)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }






/*
        //       DEPTH:   1        2        3       4
    Node* node = new Node(10,
                          new Node(20,
                                   new Node(10,
                                            new Node(20,
                                                NULL,
                                                NULL),
                                            new Node(20,
                                                NULL,
                                                NULL)),
                                   new Node(10,
                                            new Node(20,
                                                NULL,
                                                NULL),
                                            new Node(20,
                                                NULL,
                                                NULL))),
                          new Node(20,
                                   new Node(10,
                                            new Node(20,
                                                NULL,
                                                NULL),
                                            new Node(20,
                                                NULL,
                                                NULL)),
                                   new Node(10,
                                            NULL,
                                            NULL)));
    //===================================================

    MinMaxHeap minMaxHeap;

    cout << minMaxHeap.isMinMax(node);

*/




    return 0;
}
















