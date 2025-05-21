#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }

};

class DoublyList{
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        } else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = nullptr;
        }

    }
    void pop_front(void){
        if(head == nullptr){
            cout << "linkedlist is empty\n";
            return;
        }
        Node* temp = head;
        head =  head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }

        temp->next = nullptr;
        delete temp;
    }

    void printList(void){
        Node*temp = head;
        while(temp != nullptr){
            cout << temp->data << " <=> ";
            temp = temp ->next;
        }
        cout << "NULL \n";
    }

};


int main(){
    DoublyList dbll;
    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    dbll.printList();

    dbll.pop_front();
    dbll.printList();

    return 0;
}