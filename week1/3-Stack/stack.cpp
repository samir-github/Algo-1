#include <iostream>

using namespace std;
/*
#############################
#########  QUEUE  ###########
#############################
*/
template <class T>
class Queue{

private:
    struct Node{
        T value;
        Node* next;
    };
    int size_;
    Node* head_;
    Node* tail_;

public:
    Queue(){
        size_ = 0;
        head_ = NULL;
        tail_ = NULL;
    };
    // Free the memory
    ~Queue(){
        Node* tmp = head_;
        while(tmp != NULL){
            head_ = head_->next;
            delete tmp;
            tmp = head_;
        }
    }

    // Adds value to the end of the Queue.
    void push(T const& value){
        if(size_ == 0){
            head_ = new Node;
            tail_ = head_;
            tail_->next = NULL;
            tail_->value = value;
            size_++;
        }else{
            tail_->next = new Node;
            tail_ = tail_->next;
            tail_->next = NULL;
            tail_->value = value;
            size_++;
        }
    }

    // Returns value from the front of the Queue and removes it.
    T pop(){
        if(size_ > 0){
            T toReturn = head_->value;
            Node* tmp = head_;
            head_ = head_->next;
            delete tmp;
            size_--;
            return toReturn;
        } else {
            cout << " Cant pop, stack is empty ";
            return -1;
        }
    }

    // Returns value from the front of the Queue without removing it.
    T peek() const{
        if(size_ > 0){
            return head_->value;
        } else {
            cout << " Cant peek, stack is empty ";
            return -1;
        }
    }
    // Returns the number of elements in the Queue.
    int size() const{
        return size_;
    }
    // for debugging
    void DBG_getContent(){
        Node* current = head_;
        while(current != NULL){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};
/*
#############################
#########  STACK  ###########
#############################
*/
template<class T>
class Stack{

private:
    Queue<T> q;
public:

    // Adds value to the end of the Stack.
    void push(T const& value){
        q.push(value);
    }
    // Returns value from the end of the Stack and removes it.
    T pop(){
        if(q.size()){
            for(int i = 0; i < q.size()-1; i++){
                q.push(q.pop());
            }
            return q.pop();
        } else {
            cout << "Cant pop queue is empty" << endl;
            return -1;
        }
    }
    // Returns value from the end of the Stack without removing it.
    T peek() {
        if(q.size()){
            for(int i = 0; i < q.size()-1; i++){
                q.push(q.pop());
            }
            T toReturn = q.peek();
            q.push(q.pop());
            return toReturn;
        } else {
            cout << "Cant peek queue is empty" << endl;
            return -1;
        }
    }
    // Returns the number of elements in the Stack.
    int size(){
        return q.size();
    }

};





int main(){

    Stack<int> st;

    st.push(1);
    cout << st.peek() << endl;
    st.push(2);
    cout << st.peek() << endl;
    st.push(3);
    cout << st.peek() << endl;
    st.push(4);
    cout << st.peek() << endl;
    cout << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    while(st.size()){
        cout << st.pop() << " ";
    }
    cout << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;

    return 0;
}


















