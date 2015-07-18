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

// dfs that print when backtracking, if cicle is found print "BUILD ERROR" and end the recursion.
bool dfs(string project, bool in_stack[], bool built[], map<string, int> &index_of, forward_list<string> dependancies_of[], list<string> &asnwer);

int main() {

    int n, dependencies_cout;
    string project, project_to_build;
    map<string, int> index_of;
    forward_list<string> dependancies_of[10001];

    cin >> n;
    //  map the projects to index
    for (int i = 0; i < n ; i++) {

        cin >> project;
        index_of[project] = i;

    }

    // read the project we need to buld
    cin >> project_to_build;

    // read and add the dependencies of each project, to array with index project, and elements: lists with dependencies for each project.
    for (int i = 0; i < n ; i++) {
        // read how many dependencies there for i-th project, then read and add each one in project_dependence_of[i-th project]
        cin >> dependencies_cout;
        while(dependencies_cout--){
            cin >> project;
            dependancies_of[i].push_front(project);
        }
    }


    // dfs and print when backtracking, if cycle is found print "BUILD ERROR" and end the recursion
    {

        stack<string> s;
        list<string> answers;
        bool built[10001] = {};
        bool in_stack[10001] = {};

        if (dfs(project_to_build, in_stack, built, index_of, dependancies_of, answers )) {
            for (string answer : answers) {
                cout << answer << " ";
            }
            cout << endl;
        } else {
            cout << "BUILD ERROR" << endl;
        }

    }

    return 0;
}

bool dfs(string project, bool in_stack[], bool built[], map<string, int> &index_of, forward_list<string> dependancies_of[], list<string> &answer) {

    bool no_cycle = true;

    int current = index_of[project];
    for (string s : dependancies_of[current]) {
        if (in_stack[index_of[s]]) {
            no_cycle = false;
            break;
        }
        if (!built[index_of[s]]) {
            in_stack[index_of[s]] = true;
            no_cycle = dfs(s, in_stack, built, index_of, dependancies_of, answer);
        }
        if(!no_cycle){
            return false;
        }
    }


    answer.push_back(project);
    built[current] = true;
    in_stack[current] = false;
    return no_cycle;
}

















