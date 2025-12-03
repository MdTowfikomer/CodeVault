#include <iostream>
#include <list>
using namespace std;

// stack using linked list
template <class T>
class Node{
public:
    T data;
    Node* next;

    Node(T val){
        data = val;
        next = nullptr;
    }
    
};

// using STL list

template <class T>
class Stack{
    list<T> ll;
public:
    // methods of the stack
    void push(T val){
        ll.push_front(val);
    }
    
    void pop(void){
        ll.pop_front();
    }

    T top(void){
        return ll.front();
        // ll.begin()
    }

    bool isEmpty(void){
        return ll.size() == 0;
    }
};




int main(){

    Stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    
    return 0;
}