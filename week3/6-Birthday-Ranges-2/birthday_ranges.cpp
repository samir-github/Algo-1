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



class BirthdayRanges {
public:

    BirthdayRanges(){
    }

    // adds people who are born on a specific day
    void add(int day, int numberOfPeople) {
    // ...
    }

    // removes people who are born on a specific day
    void remove(int day, int numberOfPeople) {
    // ...
    }

    // returns the number of people born in a range
    int count(int startDay, int endDay) {
    // ...
    }

private:
    int day[366] = {};
};

int main() {


    BirthdayRanges br;
    for(int i : br.day){
        cout << i << endl;
    }



    return 0;
}





























