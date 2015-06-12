#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int* Sort(int* sequence,int length);

int main(){

    int arr[] = {10,3,5,8,2,-5,12,3,-13,4};

    Sort(arr, sizeof(arr)/sizeof(int));

    for ( int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}

int* Sort(int* sequence,int length){

    for(int i = 1; i < length; ++i){
        if(sequence[i] < sequence[i-1]){
            int j = i;
            do{
                swap(sequence[j], sequence[j-1]);
                --j;
            }while( j > 0 && sequence[j] < sequence[j-1]);
        }
    }

    return sequence;
}














