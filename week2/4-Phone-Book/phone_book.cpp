#include <iostream>
#include <typeinfo>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

using namespace std;



class Contact {
public:
    string name;
    int number;
    Contact(string name, int number): name(name), number(number){
    }
};

bool cmp(Contact first, Contact second){
    return(first.number < second.number);
}

class PhoneBook {
public:

    // Find the names of people based on their phone numbers.
    vector<string> lookupNames(vector<Contact> phoneBook, vector<int> numbers) {

        vector<string> answer;

        sort(phoneBook.begin(), phoneBook.end(), cmp);

        for(int i : numbers){

            int left = 0;
            int right = phoneBook.size();
            int mid = left + (right-left)/2; // or just right/2
            bool found = false;

            while(left<=right){

                if(phoneBook[mid].number > i){
                    right = mid - 1;
                    mid = left + (right-left)/2;
                }
                else if(phoneBook[mid].number < i){
                    left = mid + 1;
                    mid = left + (right-left)/2;
                } else {
                    found = true;
                    answer.push_back(phoneBook[mid].name);
                    break;
                }
            }
            if(!found){
                answer.push_back("NONE!");
            }
        }
        return answer;
    }
};






int main(){

    /*
    vector<Contact> contacts = {Contact("Plazma",12), Contact("Asen",2), Contact("Josh", 3)};
    vector<int> numbers = {12,2,5,3};
    PhoneBook phone_book;

    vector<string> answer = phone_book.lookupNames(contacts, numbers);

    for(string s : answer){
        cout << s << ", ";
    }
    cout << endl;
    */

    return 0;
}
