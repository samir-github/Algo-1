#include <iostream>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

template<class T>
class Vector {

private:

    T m_capacity = 1;
    T m_size = 0;
    T* arr = new int[m_capacity];

public:

    ~Vector(){
        delete[] arr;
    };

    // Adds value at a specific index in the Vector.
    // Complexity: O(n)
    void insert(int index, T value) {
        if(m_size == m_capacity){
            T* tmpArr = new T[m_capacity*2];
            memcpy(tmpArr, arr, (m_capacity)*sizeof(T) );
            m_capacity *= 2;
            delete[] arr;
            arr = tmpArr;
        }
        for (int i = index; i <= m_size; i++){
            T tmp = arr[i];
            arr[i] = value;
            value = tmp;
        }
        m_size++;
    }

    // Adds value to the end of the Vector.
    // Complexity: O(1)
    void add(T value) {
        if(m_size == m_capacity){
            T* tmpArr = new T[m_capacity*2];
            memcpy(tmpArr, arr, (m_capacity)*sizeof(T) );
            m_capacity *= 2;
            delete[] arr;
            arr = tmpArr;

            arr[m_size] = value;
            m_size++;
        }else{
            arr[m_size] = value;
            m_size++;
        }
    }

    // For easier debugging
    void getContent(){
        for (int i = 0; i < m_size; i++) {
            cout << get(i) << " ";
        }
        cout << endl;
    }

    // Returns value at a specific index in the Vector
    // Complexity: O(1)
    T get(int index) {
        if(index < m_size){
            return arr[index];
        }else{
            cout << "In function get(int index) index out of range" << endl;
            return -1;
        }
    }

    // Removes element at the specific index
    // Complexity: O(n)
    void remove(int index) {
        if(index >= m_size){
            cout << "In function remove(int index) index out of range" << endl;
        }else{
            if(m_size <= m_capacity/4){
                T* tmpArr = new T[m_capacity/4];
                memcpy(tmpArr, arr, index*sizeof(T));
                memcpy(tmpArr+index, arr+index+1, (m_size-index-1)*sizeof(T));
                m_capacity /= 4;
                m_size--;
                delete arr;
                arr = tmpArr;
            } else {
                memmove(arr+index, arr+index+1, (m_size-index-1)*sizeof(T));
                m_size--;
            }
        }
    }


    // Removes element at the last index
    // Complexity: O(1)
    T pop() {
        m_size--;
        return arr[m_size+1];
    }

    // Returns the number of elements in the Vector.
    // Complexity: O(1)
    int size() {
        return m_size;
    }

    // Returns the total capacity of the Vector.
    // Complexity: O(1)
    int capacity() {
        return m_capacity;
    }
};


int main(){


/*

    Vector<int> v;
    v.add(1);
    v.getContent();
    v.add(2);
    v.getContent();
    v.add(3);
    v.getContent();
    v.add(4);
    v.getContent();
    v.add(5);
    v.getContent();


    for(int i = 6; i < 18; i++){
        v.add(i);
    }
    v.getContent();

    for(int i = 0; i < 12; i++){
        v.remove(2);
        v.getContent();
    }

    v.insert(0,6);
    v.getContent();
    v.insert(1,7);
    v.getContent();
    v.insert(2,8);
    v.getContent();
    v.insert(0,9);
    v.getContent();

*/

    return 0;
}
