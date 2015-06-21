#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100000


class Sorting {
public:

    // Sorts a sequence of integers.
    void sort(int* sequence, int size) {

        short arr[MAX] = {};

        for(int i = 0; i < size; ++i){
            arr[sequence[i]]++;
        }

        for(int i = 0, j = 0; i < MAX; ++i){
            if(arr[i]){
                while(arr[i]--){
                    sequence[j] = i;
                    j++;
                }
            }
        }
    }
};


int main(){

    int arr[] = {10,3,5,8,2,5,12,3,13,4,MAX-1,0};

    Sorting srt;
    srt.sort(arr, sizeof(arr)/sizeof(int));

    for (unsigned int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}


