#include <iostream>
#include <stack>
#include <string>
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

string reverseString(string str){   // str is input string
    string ans;     // ans is output string 
    stack<char> s;   // stack to reverse the string

    for(int i = 0; i < str.size(); i++){
        s.push(str[i]);     // pusing each element into the stack
    }

    while(!s.empty()){
        char top = s.top(); // storing the stack values in top variable
        ans += top; // adding 'top' variable to ans string 
        s.pop();    // empty the stack
    }

    return ans;
}

int main(){
    // STL stack
    // stack<char> s;

    // while(!s.empty()){
    //     cout << s.top() << endl;
    //     s.pop();
    // }

    string str = "Md Towfik omer";

    cout << "reverse: "<< reverseString(str) << endl;

    return 0;
}