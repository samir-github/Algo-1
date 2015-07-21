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

#define MAX 10001


// day = height
class BinaryIndexTree {
public:

    BinaryIndexTree(){
    }

    // adds people who are born on a specific day
    void add(int day, int numberOfPeople) {

        while(day < MAX){

            born_up_to_day[day] += numberOfPeople;
            day += day & -day;

        }


    }

    // removes people who are born on a specific day
    void remove(int day, int numberOfPeople) {

        while(day < MAX){

            born_up_to_day[day] -= numberOfPeople;
            day += day & -day;

        }

    }

    // returns the number of people born in a range
    int count(int startDay, int endDay) {

        int sum = 0, startSum, endSum;
        startDay--;

        while(endDay > 0 && endDay != startDay){

            sum += born_up_to_day[endDay];
            endDay -= endDay & -endDay;

            while(startDay > endDay){

                sum -= born_up_to_day[startDay];
                startDay -= startDay & - startDay;

            }
        }

        return sum;
    }

private:
    //peple born from (i - (i&-i) + 1) untill(inclusive) i;
    int born_up_to_day[MAX] = {};
};


int main() {

    cin.sync_with_stdio(false);

    int n, k, height;
    int row_with_most_jumps = 1;
    int highest_number_of_jumps = 0;

    cin >> n >> k;

    for(int row = 1; row <= k; row++){

        int jumps_this_row = 0;
        BinaryIndexTree recruits;

        for(int i = 0; i < n; i++){

            cin >> height;

            // increment jumps by peple befor current person minus people shorter then current person
            jumps_this_row += i - recruits.count(1,height);

            // add the height of the new recruit
            recruits.add(height, 1);
        }
        if(jumps_this_row > highest_number_of_jumps){

            row_with_most_jumps = row;
            highest_number_of_jumps = jumps_this_row;
        }
    }

    cout << row_with_most_jumps << endl;

    return 0;
}





























