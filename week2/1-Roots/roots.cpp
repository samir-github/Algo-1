#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;
#define eps 0.00001

class Roots {
public:

    // Finds the square root of a number using binary search.
    double squareRoot(int number) {

        double left = 0, right = number*2;
        double mid = left + (right-left); // left + right /2
        double mid_squared = mid*mid;

        while (abs(number - mid_squared) > eps){
            if(mid_squared > number){
                right = mid;
                //mid = left + (mid-left)/2;
                mid = (left + mid) / 2;
            }else{
                left = mid;
                //mid = mid + (right-mid)/2;
                mid = (mid + right) / 2;
            }
            mid_squared = mid*mid;
        }
        return mid;
    }
};


int main(){

    int x = 9;
    Roots rt;

    cout << setprecision(5) << rt.squareRoot(121);

    return 0;
}
