#include <iostream>
#include <string>
using namespace std;



template <class T>
class Node{
public:
    T data;
    Node *next;
    Node(T val){
        data = val;
        next = nullptr;
    }
};


template <class T>
class Stack{
    Node<T> *top;
public:
    //
    Stack(){
        top = nullptr;  
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
 

    void push(T val){
        Node<T>* newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;

    }

    void pop(void){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        temp->next = nullptr;
        delete temp;
    }

    T peek(void){
        return top->data;
    }

    bool isEmpty(void){
        return top == nullptr;
    }
};




int main(){
    Stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout << s.peek() << endl;
        s.pop();
    }
    

    return 0;
}