#include <iostream>

using namespace std;


template <class T>
class Queue{

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
            cout << " Cant pop, stack is empty ";
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

private:
    struct Node{
        T value;
        Node* next;
    };

    int size_;
    Node* head_;
    Node* tail_;



};





int main(){

    Queue<int> q;
    q.push(5);
    cout << q.peek() << endl;
    q.push(6);
    q.push(7);
    q.push(8);
    cout << q.peek() << endl;
    q.DBG_getContent();
    cout << endl;
    while(q.size() > 0){
        cout << q.pop() << endl;
    }



    return 0;
}


















