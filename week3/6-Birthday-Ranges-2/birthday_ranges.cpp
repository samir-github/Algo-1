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

#define MAX 366

class BirthdayRanges {
public:

    BirthdayRanges(){
    }

    int born_up_to_day[MAX] = {};

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
//    int born_up_to_day[MAX] = {};
};

int main() {

    cin.sync_with_stdio(false);

    BirthdayRanges br;
    int arr[366] = {};
    int n, m, day, people, startDay, endDay;
    string command;

    cin >> n >> m;

    while(n--){
        cin >> day;
        ++arr[day];
    }
    for(int i = 1; i < 366; i++){
        br.add(i, arr[i]);
    }


    while(m--){
        cin >> command;
        if(command == "count"){
            cin >> startDay >> endDay;
            cout << br.count(startDay, endDay) << endl;
        }
        else if(command == "add"){
            cin >> day >> people;
            arr[day] += people;
            br.add(day, people);
        }
        else if(command == "remove"){
            cin >> day >> people;
            if(arr[day] < people){
                people = arr[day];
                arr[day] = 0;
            } else {
                arr[day] -= people;
            }
            br.remove(day, people);
        }
    }

    return 0;
}





























