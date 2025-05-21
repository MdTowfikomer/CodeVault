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
        next = nullptr;
    }
    ~Node(){
        if(next != nullptr){
            delete next;
            next = nullptr;
        }
    }
};

class List{
public:
    Node *head;
    Node *tail;
    List(){     // constructor
        head = nullptr;
        tail = nullptr;
    }
    ~List(){    // destructor
        if(head != nullptr){
            delete head;
            head = nullptr;
        }
    }

    void push_front(int val){ // push at front 
        Node *newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){    // push at back
        Node *newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
};

    void printList(Node* head){     // print list
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* spliteAtmid(Node* head){
        Node* fast = head;
        Node* slow = head;
        Node* pre = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(pre != nullptr){
            pre->next = nullptr;
        }

        return slow;
    }


    Node* reverseList(Node* head){
        Node *cur = head;
        Node *pre = nullptr;
        while(cur != nullptr){
            Node *next = cur->next;
            cur->next = pre;

            pre = cur;
            cur = next;
        }

        return pre;
    }



    Node* zigZag(Node* head){
        //split at mid
        Node* rightHead = spliteAtmid(head);

        // reverse the 2nd half
        Node* rightRev = reverseList(rightHead);

        Node* left = head;
        Node* right = rightRev;
        Node* tail = right;

        while(left != nullptr && right != nullptr){
            Node* nextLeft = left->next;
            Node* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            tail = right;

            left = nextLeft;
            right = nextRight;
        }

        if(right != nullptr){
            tail->next = right; 
        }

        return head;
       
    }



    int main(){
        List ll;
        ll.push_back(1);
        ll.push_back(2);
        ll.push_back(3);
        ll.push_back(4);
        ll.push_back(5);
        ll.push_back(6);
        printList(ll.head);

        ll.head= zigZag(ll.head);
        printList(ll.head);

        return 0;
    }