#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


class HeapSort {

public:

    // Sorts a sequence of integers.
    void sort(int* sequence, int size) {

        make_heap(sequence, size);

        while(size--){

            swap(sequence[0],sequence[size]);

            int parent = 0;

            while(parent*2+2 < size && (sequence[parent] < sequence[parent*2+1] || sequence[parent] < sequence[parent*2+2])){

                int bigger_child = sequence[parent*2+1] > sequence[parent*2+2] ? parent*2+1 : parent*2+2;

                swap(sequence[bigger_child], sequence[parent]);
                parent = bigger_child;
            }
            if(parent*2+1 < size && sequence[parent] < sequence[parent*2+1]){
                swap(sequence[parent], sequence[parent*2+1]);
            }
        }
    }

private:
    // bigger elements are higher
    void make_heap(int* seq, int size){

        for(int i = size/2; i >= 0; i--){

            int parent = i;

            while(parent*2+2 < size && (seq[parent] < seq[parent*2+1] || seq[parent] < seq[parent*2+2])){

                int bigger_child = seq[parent*2+1] > seq[parent*2+2] ? parent*2+1 : parent*2+2;

                swap(seq[bigger_child], seq[parent]);
                parent = bigger_child;
            }
            if(parent*2+1 < size && seq[parent] < seq[parent*2+1]){
                swap(seq[parent], seq[parent*2+1]);
            }
        }
    }

};


int main(){
    /*
    int arr[] = {10,3,-5,8,2,5,-12,3,13,4,0,0,20,-20,INT_MAX,INT_MIN,140,360,420,720,1337};

    HeapSort hs;
    hs.sort(arr, sizeof(arr)/ sizeof(int));

    for(int i : arr){
        cout << i << " ";
    }
    */

    return 0;
}






















