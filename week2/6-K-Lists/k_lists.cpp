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

    Node(int value = INT_MIN, Node* next = NULL): value(value), next(next){
    }
    int value;
    Node* next;
};



class KLists {
public:

    // Merge K sorted lists.
    void merge(vector<Node> lists) {

        Node answer;
        Node* answer_tail = &answer;

        make_heap(lists, lists.size());

        while(!lists.empty()){

            answer_tail->next = new Node(lists[0].value, lists[0].next);
            answer_tail = answer_tail->next;
            cout << answer_tail->value << endl;

            if(lists[0].next != NULL){

                lists[0] = *(lists[0].next);
                heapify(lists, lists.size());

            } else {

                lists[0] = lists.back();
                lists.pop_back();
                heapify(lists, lists.size());
            }
        }


        /*
        for(auto e : lists){
            cout << e.value << " ";
        }
        */

    }

private:
    //min heap
    void make_heap(vector<Node> &seq, int size){

        for(int i = size/2; i >= 0; i--){

            int parent = i;

            while(parent*2+2 < size && (seq[parent].value > seq[parent*2+1].value || seq[parent].value > seq[parent*2+2].value)){

                int smallest_child = seq[parent*2+1].value < seq[parent*2+2].value ? parent*2+1 : parent*2+2;

                swap(seq[smallest_child], seq[parent]);
                parent = smallest_child;
            }
            if(parent*2+1 < size && seq[parent].value > seq[parent*2+1].value){
                swap(seq[parent], seq[parent*2+1]);
            }
        }
    }
    void heapify(vector<Node> &seq, int size){

        int parent = 0;

            while(parent*2+2 < size && (seq[parent].value > seq[parent*2+1].value || seq[parent].value > seq[parent*2+2].value)){

                int smallest_child = seq[parent*2+1].value < seq[parent*2+2].value ? parent*2+1 : parent*2+2;

                swap(seq[smallest_child], seq[parent]);
                parent = smallest_child;
            }
            if(parent*2+1 < size && seq[parent].value > seq[parent*2+1].value){
                swap(seq[parent], seq[parent*2+1]);
            }
    }

};


int main(){



    vector<Node> input = {
        Node(3, new Node(5, new Node(7, new Node(9, NULL)))),
        Node(2, new Node(4, new Node(6, NULL))),
        Node(0, new Node(1, new Node(8, new Node(10, NULL))))
    };

    KLists klist;
    klist.merge(input);



/*
    for(auto i : input){
        while(i.next != NULL){
            cout << i.value << " ";
            i = *i.next;
        }
        cout << i.value << endl;
    }
*/

    return 0;
}


















