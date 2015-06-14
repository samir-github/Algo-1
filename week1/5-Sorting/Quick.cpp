#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int* Sort(int* sequence,int length);

int main(){

    int arr[] = {10,3,-5,8,2,5,-12,3,13,4,0,0,INT_MAX,INT_MIN};

    Sort(arr, sizeof(arr)/sizeof(int));

    for (unsigned int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}


int* Sort(int* sequence,int length){

    if(length < 2){
        return sequence;
    }

    int pivot = 0;
    int border = 1; // pivot +1

    for(int i = 1; i < length; ++i){
        if(sequence[i] < sequence[pivot]){
            swap(sequence[i], sequence[border]);
            ++border;
        }
    }
    swap(sequence[pivot], sequence[border-1]);

    Sort(sequence,border);
    Sort(sequence+border,length-border);
/*
    Commented section and the section above are doing the same thing.
    Sort(&sequence[pivot],border);
    Sort(&sequence[pivot+border],length-border);
*/

    return sequence;
}





















