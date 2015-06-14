#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int* Sort(int* sequence,int length);

int main(){

    int arr[] = {10,3,-5,8,2,5,-12,3,13,4,0,0,20,-20,INT_MAX,INT_MIN,140,360,420,720,1337};

    Sort(arr, sizeof(arr)/sizeof(int));

    for (unsigned int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}


int* Sort(int* sequence,int length){

    int mid,i,j,k;

    if(length == 2){
        if(sequence[0] > sequence[1]){
            swap(sequence[0], sequence[1]);
        }
        return sequence;
    }
    else if(length > 2){
        mid = length / 2;
        Sort(sequence,mid);
        Sort(sequence+mid, length-mid);

        // Merge
        i = 0, j = mid, k = 0;
        int* tmpArr = new int[length];
        while(i < mid && j < length){
            if(sequence[i] < sequence[j] ){
                tmpArr[k] = sequence[i];
                ++i, ++k;
            } else {
                tmpArr[k] = sequence[j];
                ++j, ++k;
            }
        }
        // add the remaining elements 1 by 1
        while(i < mid){
            tmpArr[k] = sequence[i];
            ++i, ++k;
        }
        while(j < length){
            tmpArr[k] = sequence[j];
            ++j, ++k;
        }

        memcpy(sequence, tmpArr, length*sizeof(int));
        delete[] tmpArr;
    }




    return sequence;
}





















