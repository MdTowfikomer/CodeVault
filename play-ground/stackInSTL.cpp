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

// stock span function to find the 
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

// next greater function to find the next greater element of the every elements 
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

// vaild parentheseis function
bool isValid(string s) {
    stack<char> keep;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        // check for opening brackets
        if(ch == '(' || ch == '{' || ch == '['){
            keep.push(ch);
        } else{

            if(keep.empty()){
                return false;
            }

            if(ch == ')' && keep.top() != '('){
                return false;
            }
            if(ch == '}' && keep.top() != '{'){
                return false;
            } 
            if(ch == ']' && keep.top() != '['){
                return false;
            }
            keep.pop();
        }
    }

    if(!keep.empty()){
        return false;
    }
    
    return true;
}

// Duplicate parenthesis problem

bool isDuplicateparenthesis(string str){
    stack<char> s;                          // stack to track and keep the remaining expresion

    for(int i = 0; i < str.size(); i++){
        char ch = str[i];   
        if(ch !=  ')'){
            s.push(ch);
        } else{
            if(s.top() == '('){
                cout << "Duplicate bracket found\n";
                return true;    // duplicate bracket found
            }
            while(s.top() != '('){  // or till the ')' close bracket found pop
                s.pop();
            }
            s.pop();      // pop the after poping the expression pop the open bracket as well 
        }
    }
    cout << "Expression did not have any duplicate bracket\n";
    return false; // if the expression did not have any dublicate brackets
}



int main(){ 
    string str1 = "(a+b)";
    string str2 = "(((a+b)+ c))";

    cout << isDuplicateparenthesis(str1) << endl;
    cout << isDuplicateparenthesis(str2) << endl;

    
    return 0;
}