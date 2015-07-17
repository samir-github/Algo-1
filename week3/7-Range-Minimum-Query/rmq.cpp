#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>

using namespace std;


int arr[2097152] = {};
class RMQ {
public:

    int arrStart;
    int arrEnd;

    RMQ(int arrSize){
        int i = 1;
        while( i < arrSize){
            i <<= 2;
        }
        arrStart = i; // inclusive
        arrEnd = i + arrSize; // exclusive
        for(int i = 0; i < 2097152; i++){
            arr[i] = INT_MAX;
        }
    }

    // sets the value at index
    void set(int index, int value) {
        // The actuall index of the value in the tree
        int current = arrStart + index;
        arr[current] = value;

        // travel the parents and set them to equal min(left, right)
        current /= 2;
        while(current > 0){
            arr[current] = min(arr[current*2], arr[current*2+1]);
            current /= 2;
        }
    }

    // returns the minimum value in a range
    int minInRange(int startIndex, int endIndex, int currentLeft, int currentRight, int current = 1) {
        // full overlap
        if(startIndex <= currentLeft && endIndex >= currentRight){
            return arr[current];
        }
        // no overlap
        if(startIndex > currentRight || endIndex < currentLeft){
            return INT_MAX;
        }
        //partial overlap
        int mid = currentLeft + (currentRight-currentLeft)/2;
        int a =  minInRange(startIndex, endIndex, currentLeft, mid, current * 2);
        int b = minInRange(startIndex, endIndex, mid+1, currentRight, current = current * 2 + 1);
        return min(a, b);
    }

    // build the tree after array is filled with values
    int buildTree(int curr){
        if(curr >= arrEnd){
            return INT_MAX;
        }
        else if(curr >= arrStart){
            return arr[curr];
        }
        // else
        else{
            return arr[curr] = std::min(buildTree(curr*2), buildTree(curr*2+1));
        }
    }

};


int main() {

    cin.sync_with_stdio(false);

    int n, k, tmp, index, value, startIndex, endIndex;
    string command;

    cin >> n >> k;
    RMQ rmq(n);
    for(int i = rmq.arrStart; i < rmq.arrEnd; i++){
        cin >> tmp;
        arr[i] = tmp;
    }
    rmq.buildTree(1);

    while(k--){
        cin >> command;
        if (command == "set"){
           cin >> index >> value;
           rmq.set(index, value);
        }
        else{
            cin >> startIndex >> endIndex;
            cout << rmq.minInRange(startIndex, endIndex, 0 , rmq.arrStart-1) << endl;
        }
    }

/*
    for(int i = 1; i < rmq.arrEnd; i++){
        cout << arr[i] << " ";
    }
*/


    return 0;
}





























