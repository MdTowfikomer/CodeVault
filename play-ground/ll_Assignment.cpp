#include <iostream>
#include <list>
#include <iterator>
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
public:
    Node *head;
    Node *tail;
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
    
    int listSize(void){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};


void printList(Node *head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void getIntersectionNode(Node *headA, Node *headB) { // ll1 and ll2 
    Node* ptrA = headA;
    Node* ptrB = headB;

    while(ptrA != NULL || ptrB != NULL){

        if(ptrA == ptrB){
            cout << "intersect element found: " << ptrA->data << endl;
            return;
        }

        if(ptrA == NULL){
            ptrA = headB;
            ptrB = ptrB->next;
        } else if(ptrB == NULL){
            ptrB = headA;
            ptrA = ptrA->next;
        } else {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }

    cout << "NO interserted element found..!\n";
    return;
}




int main(){
    List ll1;
    List ll2;
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);
    ll1.push_back(6);
    ll1.push_back(7);

    ll2.push_back(4);
    ll2.push_back(5);

    // Find the node with value 6 in ll1 (4th node, index 3)
    Node *temp = ll1.head;
    for (int i = 0; i < 3; i++) {
        if (temp == NULL) break;
        temp = temp->next;
    }
    // now temp pointes the 4th node

    if (temp != NULL) {
        // Link node 5 (ll2's tail) to node 6
        ll2.tail->next = temp;
        // Update ll2's tail to node 7 (ll1's tail)
        ll2.tail = ll1.tail;
    }

    getIntersectionNode(ll1.head,ll2.head);


    // Break the link from node 5 to node 6 before destruction to avoid double deletion
    if (ll2.head != NULL && ll2.head->next != NULL) {
        Node *five_node = ll2.head->next; // node 5
        five_node->next = NULL;        // Break link to shared node
        ll2.tail = five_node;              // Update ll2's tail to node 5
    }

    return 0;
    return 0;
}