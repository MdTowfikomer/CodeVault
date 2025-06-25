#include <iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(void){
        head = tail = nullptr;
    }

    // push_back
    void push(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // pop_front
    void pop(void){
                
       if(isEmpty()){
            cout << "Queue is empty. \n";
            return ;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int front(void){
        
       if(isEmpty()){
            cout << "Queue is empty. \n";
            return -1;
        }

        return head->data;
    }

    bool isEmpty(void){
        return head == nullptr;
    }
};



int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isEmpty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
     
    return 0;
}