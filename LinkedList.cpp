#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){ // Constructor
        data = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
    Node *head;
    Node *tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(void){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int val, int pos){
        Node *newNode = new Node(val);

        Node *temp = head;
        for(int i = 0; i < pos-1; i++){
            if(temp == NULL){
                cout << "INVALID position..." << endl;
                return;
            }
            temp = temp ->next;
        }
        newNode -> next = temp -> next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head == NULL){
            cout << "List is empty\n";
        }
        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
         if(head == NULL){
            cout << "List is empty\n";
        }
        Node *temp = head;
        while(temp->next->next != NULL){
            temp = temp ->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
};



int main(){
   List ll;
   ll.push_back(1);
   ll.push_back(2);
   ll.push_back(3);
   ll.push_front(0);
   ll.printList();
   ll.pop_front();
   ll.pop_back();
    ll.printList();

    return 0;
}