#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


class Sorting {
public:

    // Sorts a sequence of integers.
    void sort(int* sequence, int size) {

        int mid,i,j,k;

        if(size == 2){
            if(sequence[0] > sequence[1]){
                swap(sequence[0], sequence[1]);
            }
            return;
        }
        else if(size > 2){
            mid = size / 2;
            Sort(sequence,mid);
            Sort(sequence+mid, size-mid);

            // Merge
            i = 0, j = mid, k = 0;
            int* tmpArr = new int[size];
            while(i < mid && j < size){
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
            while(j < size){
                tmpArr[k] = sequence[j];
                ++j, ++k;
            }

            memcpy(sequence, tmpArr, size*sizeof(int));
            delete[] tmpArr;
        }
    }
};


int main(){

    int arr[] = {10,3,-5,8,2,5,-12,3,13,4,0,0,20,-20,INT_MAX,INT_MIN,140,360,420,720,1337};

    Sorting srt;
    srt.sort(arr, sizeof(arr)/sizeof(int));

    for (unsigned int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}

