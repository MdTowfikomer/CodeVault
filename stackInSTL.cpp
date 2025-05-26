#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// function to push the element in the bottom
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


// function to reverse the string using stack
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


// function to reverse the stack
void reverseStack(stack<int>& s){

    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);

    pushAtback(s, temp);

}

void printStack(stack<int> &s){
    
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return;
}

vector<int> stockSpan(vector<int>& stock){
    vector<int> span(stock.size(), 0);
    stack<int> s;// stack
    s.push(0); 
    span[0] = 1;
    
    for(int i = 1; i < stock.size(); i++){
        int curPrice = stock[i];
        while(!s.empty() && curPrice >= stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i] = i+1;
        } else{
            int prevHig = s.top();
            span[i] = i - prevHig;
        }
        s.push(i);
    }

    return span;
}

vector<int> nexGreater(vector<int>& vec){
    int n = vec.size();
    vector<int> ans(n,0);// initializing ans vector with size of vec 
    stack<int> s;   // initializing stack s
    ans[n-1] = -1;  // last element have no next greater so it is -1
    s.push(vec[n-1]);

    
    for(int i = n-2; i >= 0; i--){
        int cur = vec[i];
        while(!s.empty() && cur >= s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        } else {    
            ans[i] = s.top();
        }
        s.push(cur);
    }

    return ans;
}


int main(){ 
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans(arr.size(), 0);

    ans = nexGreater(arr);
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}