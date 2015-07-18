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
#include <cstring>

using namespace std;


int main() {

    list<int> student_numbers;
    int students, number, calls = 0;
    forward_list<int> friends_of_student[1024];

    cin >> students;
    // save the phone of each studen in a list
    for (int i = 0; i < students ; i++) {

        cin >> number;
        student_numbers.push_back(number);

    }
    // for each student number, add the numbers it can contact in a array of lists
    // i = the number of the student, elements of each list = the numbers he can call
    for (int i : student_numbers) {

        int amount_of_friends;
        cin >> amount_of_friends;
        for (int j = 0; j < amount_of_friends ; j++) {

            cin >> number;
            friends_of_student[i].push_front(number);

        }

    }

    // BFS
    queue<int> q;
    bool visited[1024] = {};
    for (int i : student_numbers) {
        // add to queue if not visited and increment calls; ( not visited = cant be called from someone who was already called )
        if (!visited[i]) {
            q.push(i);
            calls++;
            visited[i] = true;

        }
        // add each not visited friend of the sudent in the front of the queue to the queue
        while (!q.empty()) {
            int current_student = q.front();
            for (int friend_j : friends_of_student[current_student]) {
                if (!visited[friend_j]) {
                    q.push(friend_j);
                    visited[friend_j] = true;
                }
            }
            q.pop();
        }
    }

    cout << calls << endl;

    return 0;
}





























