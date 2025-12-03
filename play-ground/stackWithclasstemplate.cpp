#include <iostream>
#include <vector>
using namespace std;

// stack implementation using class template with vectors

template<class T>
class Stack{
    vector<T> vec;
public:

    void push(T val){
        vec.push_back(val);
    }

    void pop(void){
         if(isEmpty()){
            cout << "stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    T top(void){
        // if(isEmpty()){
        //     cout << "stack is empty\n";
        //     return -1;
        // }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(void){
        return vec.size() != 0 ? false : true;
    }
};


int main(){
    Stack<char> s;
    s.push(75);
    s.push(74);
    s.push(73);
    s.push(72);
    s.push(71);

    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    
    return 0;
}