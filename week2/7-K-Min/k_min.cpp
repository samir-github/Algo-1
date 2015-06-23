#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class KMin {
public:

    // Finds the k-th minimum element in an unsorted collection.
    int kthMinimum(vector<int> numbers, int k) {

        make_heap(numbers, numbers.size());

        while(--k){
            numbers.front() = numbers.back();
            numbers.pop_back();
            heapify(numbers);
        }

        return numbers.front();

    }


private:
    void make_heap(vector<int> &numbers, int size){

        for(int i = size/2; i >= 0; --i){

            heapify(numbers, i);
        }
    }

    void heapify(vector<int> &numbers, int i = 0){

        int size = numbers.size();
        while(i*2+2 < size && numbers[i] > min(numbers[i*2+1], numbers[i*2+2])){
            int id_min = numbers[i*2+1] < numbers[i*2+2] ? i*2+1 : i*2+2;
            swap(numbers[i], numbers[id_min]);
            i = id_min;

        }
        if(i*2+1 < size && numbers[i] > numbers[i*2+1]){
            swap(numbers[i], numbers[i*2+1]);
        }

    }
};





int main(){

/*
    vector<int> numbers = {10,9,8,1,1,1,2,3,7,6,4,5,0};

    KMin kmin;
    kmin.kthMinimum(numbers, 1);
    kmin.kthMinimum(numbers, 2);
    kmin.kthMinimum(numbers, 3);
    kmin.kthMinimum(numbers, 4);
    kmin.kthMinimum(numbers, 5);
*/




    return 0;
}




















