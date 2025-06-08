#include <iostream>
using namespace std;

class Queue{
    int *arr;

    int curSize, capacity;
    int f, r;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        f = 0;
        r = -1;
        curSize = 0;
    }   // dynamically array is initialized

    void push(int val){
        if(curSize == capacity){
            cout << "queue is full...\n";
            return;
        }
        r = (r+1)%capacity;
        arr[r] = val;
        curSize++;
    }

    void pop(void){
        if(empty()){
            cout << "Queue is EMPTY\n";
            return;
        }
        f = (f+1)%capacity;
        curSize--;
    }

    int front(void){
        if(empty()){
            cout << "Queue is EMPTY\n";
            return -1;
        }
        return arr[f];
    }

    bool empty(void){
        return curSize == 0;
    }
    
};



int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

   cout <<  q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    


    return 0;
}