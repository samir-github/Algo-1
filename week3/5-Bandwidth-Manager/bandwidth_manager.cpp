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

            protocol_queue[priority].push(payload);
            if (priority < highest_priority_with_data) {
                highest_priority_with_data = priority;
            }
/*
            priority_heap.push_back(Node(priority, payload));
            push_heap(priority_heap.begin(), priority_heap.end());
*/

    }

    //returns the payload of the packet which should be sent
    string send(){

        for(int i = highest_priority_with_data; i < 6; i++){
            if(!protocol_queue[i].empty()){
                string to_send = protocol_queue[i].front();
                protocol_queue[i].pop();
                highest_priority_with_data = i;
                return to_send;
            }
        }
        return "Nothing to send!";



/*
        if(!priority_heap.empty()){

            string payload = priority_heap.front().payload;
            pop_heap(priority_heap.begin(), priority_heap.end());
            priority_heap.pop_back();
            return payload;
        } else {
            return "Nothing to send!";
        }
*/
    }

private:

    queue<string> protocol_queue[6];
    int highest_priority_with_data = 0;


/*
    struct Node {
    public:
        Node(int priority, string payload){
            this->payload = payload;
            this->priority = priority;
        }<< end
        static map<string,int> p;
        int priority;
        string payload;
        bool operator < (const Node& other) const {
            return priority < other.priority;
        }
    };
    vector<Node> priority_heap;
*/
};

int main() {

    string command, protocol, payload;
    BandwidthManager bm;
    map<string, int> priority_of= {{"ICMP", 0}, {"UDP", 1}, {"RTM", 2}, {"IGMP", 3}, {"DNS", 4}, {"TCP", 5}};
    int n;
    cin >> n;

    while(n--) {
        cin >> command;
        if(command == "rcv") {
            cin >> protocol >> payload;
            bm.rcv(priority_of[protocol], payload);
        }
        if(command == "send"){
            cout << bm.send() << endl;
        }
    }
    return 0;
}





























