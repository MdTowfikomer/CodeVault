#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(val);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return;
    }

    void pop(void){
        q1.pop();
    }

    int top(){
        return q1.front();
    }

    bool empty(void){
        return q1.empty();
    }
};


int main(){
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    
    return 0;
}
