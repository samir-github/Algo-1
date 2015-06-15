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


double RootOf(double input);

int main(){

    int x = 9;
    cout << setprecision(5) << RootOf(1);

    return 0;
}

double RootOf(double input){

    char s;

    double left = 0, right = input;
    double mid = left + (right-left)/2; // left + right /2
    double mid_squared = mid*mid;

    while (abs(input - mid_squared) > eps){
        if(mid_squared > input){
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














