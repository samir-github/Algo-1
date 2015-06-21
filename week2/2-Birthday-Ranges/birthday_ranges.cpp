#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Pair {
public:
    Pair(int start, int end){
        this->start = start;
        this->end = end;
    }
    Pair();
    int start;
    int end;
};

class BirthdayRanges {
public:

    // Returns a vector with the number of people born in the specific ranges.
    vector<int> birthdaysCount(vector<int> birthdays, vector<Pair> ranges) {

        vector<int> answer;
        int index_array[366] = {0};
        int birthdays_up_to_day = 0;
        int born_in_range = 0;
        sort(birthdays.begin(), birthdays.end());

        for(int i = 0; i < 366; i++){
            static auto j = birthdays.begin();

            index_array[i] = birthdays_up_to_day;
            while(i == *j){
                ++index_array[i];
                ++birthdays_up_to_day;
                ++j;
            }
        }

        for(unsigned int i = 0; i < ranges.size(); i++){
            born_in_range = index_array[ranges[i].end] - index_array[ranges[i].start-1];
            answer.push_back(born_in_range);
        }


        return answer;
    }
};

vector<int> birthdays_count(vector<int> &birthdays, vector<pair<int,int> > &ranges);

int main(){
    // 3,17,4,2
    vector<int> birthdays = {13,15,15,17,1,2,2,3,4,5,5,6,7,8,9,10,10};
    //vector<pair<int,int> > ranges = {make_pair(2,3),make_pair(1,20), make_pair(5,7),make_pair(5,5)};
    vector<Pair> ranges = {Pair(2,3),Pair(1,20), Pair(5,7),Pair(5,5)};

    BirthdayRanges br;
    vector<int> answer = br.birthdaysCount(birthdays, ranges);

    for(int i : answer){
        cout << i << " ";
    }
    cout << endl;

/*  Trying out the c++ 11 loop instead
    for(auto it = answer.begin(); it != answer.end(); it++){
        cout << *it << " ";
    }
*/
    return 0;
}








