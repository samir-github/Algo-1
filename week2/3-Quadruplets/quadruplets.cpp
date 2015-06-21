#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Quadruplets {
public:

    // Returns the number of quadruplets that sum to zero.
    int zeroQuadrupletsCount(int* a, int* b, int* c, int* d, int size) {

        if(size == 0) return 0;

        int count = 0;
        int permutations = size*size;

        int* a_and_b_permutations = new int[size * size];
        int* c_and_d_permutations = new int[size * size];

        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){

                a_and_b_permutations[i*size + j] = a[i] + b[j];
                c_and_d_permutations[i*size + j] = c[i] + d[j];
            }
        }

        sort(c_and_d_permutations, c_and_d_permutations + permutations );

        for(int i = 0; i < permutations; ++i){

            int mid,left,right,target;
            target = -a_and_b_permutations[i];
            mid = permutations/2;
            left = 0;
            right = permutations-1;

            while(left <= right){
                if(c_and_d_permutations[mid] < target){

                    left = mid + 1;
                    mid = mid + (right - mid+1)/2;
                }
                else if(c_and_d_permutations[mid] > target){

                    right = mid-1;
                    mid = left + (mid-1 - left)/2;
                } else {

                    int k = mid;
                    while(c_and_d_permutations[k] == target){
                        ++count;
                        ++k;
                    }
                    k = mid-1;
                    while(c_and_d_permutations[k] == target){
                        ++count;
                        --k;
                    }
                    break;
                }
            }
        }
        return count;
    }
};



int zero_quadruplets_count(vector<int> a,vector<int>  b,vector<int>  c,vector<int>  d);

int main(){

    int a[3] = {5, 3, 4};
    int b[3] = {-2, -1, 6};
    int c[3] = {-1, -2, 4};
    int d[3] = {-1, -2, 7};

    Quadruplets quadruplets;
    cout << quadruplets.zeroQuadrupletsCount(a, b, c, d, sizeof(a)/sizeof(int));

    return 0;
}

