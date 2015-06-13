#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100000

int* Sort(int* sequence,int length);

int main(){

    int arr[] = {10,3,5,8,2,5,12,3,13,4,MAX-1,0};

    Sort(arr, sizeof(arr)/sizeof(int));

    for ( int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}

int* Sort(int* sequence,int length){

    short arr[MAX] = {};

    for(int i = 0; i < length; ++i){
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

    return sequence;
}














