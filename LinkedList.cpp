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

     bool isPalindrome() {
        // fist find the mid 
        // reverse after the mid 
        // compare it
        Node *lastNode = head;
        Node *midNode = head;
        while(lastNode != NULL && lastNode->next != NULL){
            midNode = midNode -> next;
            lastNode = lastNode->next->next;
        }
        // Now reverse after the mid
        Node *cur = midNode;
        Node *pre = NULL;
        while(cur != NULL){
            Node *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        // comparing the two halfes of the LL
        Node* secHead = pre;
        Node* firHead = head;

        while(firHead != NULL && secHead != NULL){
            if(firHead -> data != secHead -> data){
                cout << "Invalid palindrome \n";
                return false;
            }
            firHead = firHead->next;
            secHead = secHead->next;
        }
        cout << "Valid palindrome \n";
        return true;
    }

    int getSize(){
        Node *temp = head;
        int size = 0;
        
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        return size;
    }

    void removeNth(int n){ // n according to last nodes
        int size = getSize();
        if (n <= 0 || n > size) {
        cout << "Invalid position to delete." << endl;
        return;
        }

        if (n == size) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
        }

        Node *pre = head;
        for(int i = 0; i < size-n; i++){
            pre = pre->next;
        }
        Node *toDelete = pre->next;
        pre->next = pre->next->next;
        delete toDelete;
    }
};


    bool hasCycle(Node* head) {
        Node *fast = head;
        Node *slow = head;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow){
                cout << "LL loop exist\n";
                return true;
                break;
            }
        }
        cout << "LL loop not exist \n";
        return false;
    }

    void removeCycle(Node* head){
        // detect cycle
        Node* fast = head;
        Node* slow = head;
        bool isCycle = false;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                cout << "Cycle/loop detected" << endl;
                isCycle = true;
                break;
            }       
        }
        if(!isCycle){
            cout << "Cycle/loop not detected" << endl;
        }

        slow = head;
        if(slow == fast){ // special case for slow and head at the same position
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = NULL; // remove cycle
        } else{
        Node* pre = fast;
        while(fast != slow){
            pre = fast;
            fast = fast->next;
            slow = slow->next;
        }
        pre -> next = NULL;
        }
    }



int main(){
   List ll;
   ll.push_back(1);
   ll.push_back(2);
   ll.push_back(3);
   ll.push_back(4);
   ll.push_back(5);
   ll.push_back(6);
   ll.tail->next = ll.head;

   removeCycle(ll.head);
//    ll.tail->next = NULL;  // Break the cycle before destructor runs (used for deactivating the destructor)
    ll.printList();

   
    return 0;
}