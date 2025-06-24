#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &Q){
    stack<int> S;   // implementation of stack 
    while(!Q.empty()){  
        S.push(Q.front()); //   copying the  elements to stack from queue
        Q.pop();
    }
    while(!S.empty()){  // pushing the data in the reverse order in the queue
        Q.push(S.top());
        S.pop();
    }
return;
}

int main(){
    queue<int> q;
    for(int i = 0; i < 5; i++){
        q.push(i+1);
    }
    
    reverseQueue(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return  0;
}