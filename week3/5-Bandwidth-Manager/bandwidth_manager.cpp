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

class BandwidthManager{
public:

    //receives a packet with specified protocol and payload
    void rcv(int priority,const string payload) {

        priority_heap.push_back(Node(priority, payload));
        push_heap(priority_heap.begin(), priority_heap.end());

    }

    //returns the payload of the packet which should be sent
    string send(){

        if(!priority_heap.empty()){

            string payload = priority_heap.front().payload;
            pop_heap(priority_heap.begin(), priority_heap.end());
            priority_heap.pop_back();
            return payload;
        } else {
            return "Nothing to send!";
        }
    }

private:

    struct Node {
    public:
        Node(int priority, string payload){
            this->payload = payload;
            this->priority = priority;
        }
        static map<string,int> p;
        int priority;
        string payload;
        bool operator < (const Node& other) const {
            return priority < other.priority;
        }
    };
    vector<Node> priority_heap;
};

int main() {

    string command, protocol, payload;
    BandwidthManager bm;
    map<string, int> priority_of= {{"ICMP", 1000}, {"UDP", 900}, {"RTM", 800}, {"IGMP", 700}, {"DNS", 600}, {"TCP", 500}};

    while(cin >> command) {
        if(command == "rcv") {
            cin >> protocol >> payload;
            bm.rcv(priority_of[protocol], payload);
        }
        if(command == "send"){
            cout << bm.send() << endl << endl;
        }
    }

    return 0;
}





























