#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

#define sz 6
using namespace std;



class ClosestCoffeeStore {
public:

    // Finds the closest coffee store to a point.
    int closestCoffeeStore(bool** graph, bool* isCoffeStore, int size, int startingPoint) {

        bool* visited = new bool[size];
        memset(visited, 0, sizeof(bool)*size);

        queue<int> q;
        q.push(startingPoint);
        visited[startingPoint] = true;

        while(!q.empty()){
            if(isCoffeStore[q.front()]){
                return q.front();
            }
            for(int i = 0; i < size; i++){
                if (graph[q.front()][i]){
                    if(!visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
            q.pop();
        }

        delete[] visited;
        return -1;
    }
};


/*
int main(){


    bool** arr_p_p = new bool*[sz]{
                        new bool[sz] {0, 1, 0, 1, 0, 0},
                        new bool[sz] {1, 0, 1, 0, 0, 0},
                        new bool[sz] {0, 1, 0, 0, 1, 0},
                        new bool[sz] {1, 0, 0, 0, 0, 0},
                        new bool[sz] {0, 0, 1, 0, 0, 1},
                        new bool[sz] {0, 0, 0, 0, 1, 0} };

    bool* is_coffe_shop = new bool[sz] {0, 0, 1, 0, 0, 1};


    ClosestCoffeeStore closed_coffe_shop;

    cout << closed_coffe_shop.closestCoffeeStore(arr_p_p, is_coffe_shop, sz, 0);





    return 0;
}
*/
























