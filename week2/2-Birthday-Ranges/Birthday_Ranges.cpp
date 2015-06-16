#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> birthdays_count(vector<int> &birthdays, vector<pair<int,int> > &ranges);

int main(){

    vector<int> birthdays = {13,15,15,17,1,2,2,3,4,5,5,6,7,8,9,10,10};
    vector<pair<int,int> > ranges = {make_pair(2,3),make_pair(1,20), make_pair(5,7),make_pair(5,5)};

    vector<int> answer = birthdays_count(birthdays, ranges);

    for(auto it = answer.begin(); it != answer.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}



vector<int> birthdays_count(vector<int> &birthdays, vector<pair<int,int> > &ranges) {

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

    for(auto it = ranges.begin(); it != ranges.end(); it++){
        born_in_range = index_array[it->second] - index_array[it->first-1];
        answer.push_back(born_in_range);
    }




    return answer;
}











