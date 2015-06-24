#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;


class Median{
public:
    Median(){
        min_heap.insert(INT_MAX);
        max_heap.insert(INT_MIN);
    }

  //inserts the number and returns the median
    int insert(int number) {

        if(max_heap.size() == min_heap.size()){
            if(number < *max_heap.begin()){
                min_heap.insert(*max_heap.begin());
                max_heap.erase(max_heap.begin());
                max_heap.insert(number);
            } else {
                min_heap.insert(number);
            }
        } else {
            if(number > *min_heap.begin()){
                max_heap.insert(*min_heap.begin());
                min_heap.erase(min_heap.begin());
                min_heap.insert(number);
            } else {
                max_heap.insert(number);
            }

        }
        return *min_heap.begin();
    }
private:

    class cmp {
    public:
        bool operator() (int first, int second){
            return first > second;
        }
    };
    set<int> min_heap;
    set<int, cmp> max_heap;


};


int main() {

/*
    Median median;

    cout << median.insert(5) << endl;
    cout << median.insert(6) << endl;
    cout << median.insert(7) << endl;
    cout << median.insert(4) << endl;
    cout << median.insert(3) << endl;
    cout << median.insert(10) << endl;
    cout << median.insert(20) << endl;
    cout << median.insert(30) << endl;
    cout << median.insert(40) << endl;
    cout << median.insert(50) << endl;
*/

    return 0;
}
