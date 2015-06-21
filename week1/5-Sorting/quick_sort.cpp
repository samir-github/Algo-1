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

        if(size < 2){
            return;
        }

        int pivot = 0;
        int border = 1; // pivot +1

        for(int i = 1; i < size; ++i){
            if(sequence[i] < sequence[pivot]){
                swap(sequence[i], sequence[border]);
                ++border;
            }
        }
        swap(sequence[pivot], sequence[border-1]);

        Sorting::sort(sequence,border);
        Sorting::sort(sequence+border,size-border);
    /*
        Commented section and the section above are doing the same thing.
        Sort(&sequence[pivot],border);
        Sort(&sequence[pivot+border],size-border);
    */
    }
};

int main(){

    int arr[] = {10,3,-5,8,2,5,-12,3,13,4,0,0,INT_MAX,INT_MIN};

    Sorting srt;
    srt.sort(arr, sizeof(arr)/sizeof(int));

    for (unsigned int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}


