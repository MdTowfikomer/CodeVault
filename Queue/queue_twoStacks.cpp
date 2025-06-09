#include <iostream>
#include <stack>
using namespace std;

// APPORACH - 1
class Queue{
    stack<int> s1;
    stack<int> s2;
public:
    // O(n)
    void push(int val){     // empty the stack 1
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);   // add the val to the stack

        while(!s2.empty()){     // add the old values back to the s1 stack
            s1.push(s2.top());
            s2.pop();
        }
    }
    // O(1)
    void pop(void){
        s1.pop();
    }

    // O(1)
    int front(void){
        return s1.top();
    }
    
    bool empty(void){
        return s1.empty();
    }
};


int main(){
    Queue q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;

}