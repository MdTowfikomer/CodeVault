#include <iostream>
#include <stack>
using namespace std;


void pushAtback(stack<int>& s, int val){
    if(s.empty()){ // base case
        s.push(val);
        return;
    }

    int temp = s.top(); // storing top value in temp variable
    s.pop();
    pushAtback(s,val); // recursive call

    s.push(temp);   // pushing the old top value in the stack
}



int main(){
    // STL stack
    stack<int> s;

    pushAtback(s, 6);

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);


    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }


    return 0;
}