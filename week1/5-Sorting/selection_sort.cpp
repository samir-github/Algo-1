#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>

using namespace std;

class Sorting {
public:

    // Sorts a sequence of integers.
    void sort(int* sequence, int size) {
        int min_element;
        int min_element_index;

        for(int i = 0; i < size-1; ++i){
            min_element = sequence[i];
            min_element_index = i;
            for(int j = i+1; j < size; ++j){
                if(sequence[j] < min_element){
                    min_element = sequence[j];
                    min_element_index = j;
                }
            }
            swap(sequence[i], sequence[min_element_index]);
        }
    }
};

int main(){
/*
    int arr[] = {10,3,5,8,2,-5,12,3,-13,4};

    Sorting srt;

    srt.sort(arr, sizeof(arr)/sizeof(int));

    for ( int i = 0; i < sizeof(arr)/sizeof(int); ++i){
            cout << arr[i] << " ";
    }
*/
    return 0;
}




















