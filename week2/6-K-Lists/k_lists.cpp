#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <utility>
#include <iomanip>
#include <cstring>

using namespace std;


double pw(double a, int n) {

    double ret = 1;
    while (n) {

        if (n%2 == 1){
            ret *= a;
        }
        a *= a;
        n /= 2;

    }
    return ret;
}

double rec_pw(double a, int n) {

    if(n == 0) return 1;
    if(n == 1) return a;
    double t = rec_pw(a, n/2);
    if(n%2 == 0){
        return t*t;
    }
    return t*t*a;

}

int main() {

    cout << rec_pw(2, 5) << endl;








    return 0;
}





























