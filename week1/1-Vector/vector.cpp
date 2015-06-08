#include <iostream>
#include <cstring>

using namespace std;

class vect {

public:

    // Adds value at a specific index in the Vector.
    void insert(int index, int value){
        if(m_size == m_capacity){
            int* tmpArr = new int[m_capacity*2];
            memcpy(tmpArr, arr, (m_capacity)*sizeof(int) );
            m_capacity *= 2;
            delete arr;
            arr = tmpArr;
        }
        for (int i = index; i <= m_size; i++){
            int tmp = arr[i];
            arr[i] = value;
            value = tmp;
        }
        m_size++;

    }
    // Adds value to the end of the Vector.
    void add(int value){
        if(m_size == m_capacity){
            int* tmpArr = new int[m_capacity*2];
            memcpy(tmpArr, arr, (m_capacity)*sizeof(int) );
            m_capacity *= 2;
            delete arr;
            arr = tmpArr;

            arr[m_size] = value;
            m_size++;
        }else{
            arr[m_size] = value;
            m_size++;
        }
    }

    void getContent(){
        for ( int i = 0; i < m_size; i++){
            cout << get(i) << " ";
        }
        cout << endl;
    }

    // Returns value at a specific index in the Vector
    int get(int index){
        if(index < m_size){
            return arr[index];
        }else{
            cout << "In function get(int index) index out of range" << endl;
            return -1;
        }
    }

    // Removes element at the specific index
    void remove(int index){
        if(index >= m_size){
            cout << "In function remove(int index) index out of range" << endl;
        }else{
            if(m_size <= m_capacity/4){
                int* tmpArr = new int[m_capacity/4];
                memcpy(tmpArr, arr, index*sizeof(int));
                memcpy(tmpArr+index, arr+index+1, (m_size-index-1)*sizeof(int));
                m_capacity /= 4;
                m_size--;
                delete arr;
                arr = tmpArr;
            } else {
                memmove(arr+index, arr+index+1, (m_size-index-1)*sizeof(int));
                m_size--;
            }
        }
    }

    // Removes element at the last index
    void pop(){
        m_size--;
    }

    // Returns the number of elements in the Vector.
    int size(){
        return m_size;
    }
    // Returns the total capacity of the Vector.
    int capacity(){
        return m_capacity;
    }

private:
    int m_capacity = 1;
    int m_size = 0;
    int* arr = new int[m_capacity];

};




int main(){



    /*
    vect v;
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
