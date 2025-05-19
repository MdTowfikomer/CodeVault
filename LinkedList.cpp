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

    void printList(){
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

    void searchItr(int key){
        Node* temp = head;
        int pos = 0;
        while(temp != NULL){
            if(temp-> data == key){
                cout << "found at index: " << pos << endl;
                return;
            }
            temp = temp -> next;
            pos++;
        }
        cout << "Key not found..." << endl;
    }

    int searchRec(int key){
        return helper(head, key);
    }
    int helper(Node* temp, int key){
        if(temp == NULL){
            return -1;
        }

        if(temp->data == key){
            return 0;
        }
        int idx = helper(temp->next, key);

        if(idx == -1){
            return -1;
        }

        return idx + 1;
    }



    void reverseList(){
        Node *cur = head;
        Node *pre = NULL;

        while(cur != NULL){
            Node* next = cur -> next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = pre;
    }

    void midList(){
        Node *lastPtr = head;
        Node *midPtr = head;
        while(lastPtr != NULL && lastPtr->next != NULL){
            lastPtr = lastPtr->next->next;
            midPtr = midPtr->next;
        }
    }

};



int main(){
   List ll;
   ll.push_back(1);
   ll.push_back(2);
   ll.push_back(3);
   ll.push_back(4);
   ll.printList();
   ll.reverseList();
   ll.printList();


   


    return 0;
}