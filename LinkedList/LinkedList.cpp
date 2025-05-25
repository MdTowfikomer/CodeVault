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
    List(){
        head = nullptr;
        tail = nullptr;
    }
    ~List(){
        if(head != nullptr){
            delete head;
            head = nullptr;
        }
    }

    void push_front(int val){
        Node *newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);

        if(head == nullptr){
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
            if(temp == nullptr){
                cout << "INVALID position..." << endl;
                return;
            }
            temp = temp ->next;
        }
        newNode -> next = temp -> next;
        temp->next = newNode;
    }
    
    void pop_front(){
        if(head == nullptr){
            cout << "List is empty\n";
        }
        Node *temp = head;
        head = head->next;
        
        temp->next = nullptr;
        delete temp;
    }
    
    void pop_back(){
        if(head == nullptr){
            cout << "List is empty\n";
        }
        Node *temp = head;
        while(temp->next->next != nullptr){
            temp = temp ->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }
    
    void searchItr(int key){
        Node* temp = head;
        int pos = 0;
        while(temp != nullptr){
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
        if(temp == nullptr){
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
        Node *pre = nullptr;
        
        while(cur != nullptr){
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
        while(lastPtr != nullptr && lastPtr->next != nullptr){
            lastPtr = lastPtr->next->next;
            midPtr = midPtr->next;
        }
        cout << "mid element: "<< midPtr->data << endl;
    }
    
    bool isPalindrome() {
        // fist find the mid 
        // reverse after the mid 
        // compare it
        Node *lastNode = head;
        Node *midNode = head;
        while(lastNode != nullptr && lastNode->next != nullptr){
            midNode = midNode -> next;
            lastNode = lastNode->next->next;
        }
        // Now reverse after the mid
        Node *cur = midNode;
        Node *pre = nullptr;
        while(cur != nullptr){
            Node *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        // comparing the two halfes of the LL
        Node* secHead = pre;
        Node* firHead = head;
        
        while(firHead != nullptr && secHead != nullptr){
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
        
        while(temp != nullptr){
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

void printList(Node* head){
    Node *temp = head;
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

bool hasCycle(Node* head) {
    Node *fast = head;
    Node *slow = head;
    
    while(fast != nullptr && fast -> next != nullptr){
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
       while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            cout << "cycle detected "<< endl;
            isCycle = true;
            break;
        }
       }

       if(!isCycle){
        cout << "Cycle not detected..." << endl;
        return;
       }    
       // reinitialize slow to head
       slow = head;

       // Two cases of cycle in a LL
       // last node connect to first
       if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = nullptr;
       } else{ // last node connected to any random node except first node
        Node *prev = fast;
        while(fast != slow){
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = nullptr;
       }
       cout << "Successfully Breaked the cycle/loop from the LL\n";
    }

    Node* merge(Node* head,Node* rightHalf){
        List ans;
        Node* L = head;
        Node* R = rightHalf;

        while(L != nullptr && R != nullptr){
            if(L->data < R->data){
                ans.push_back(L->data);
                L = L -> next;
            } else{
                ans.push_back(R->data);
                R = R->next;
            }
        }

        while(L != nullptr){
            ans.push_back(L->data);
            L = L -> next;
        }
        while(R != nullptr){
            ans.push_back(R->data);
             R = R->next;
        }

        return ans.head;
    }



    Node* splitAthalf(Node* head){
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

    Node* mergeSort(Node* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        Node* rightHalf = splitAthalf(head);

       Node *left = mergeSort(head); // left half
        Node *right = mergeSort(rightHalf);   // right half

       return merge(left, right);     // merge two halves

    }


int main(){
   List ll;
   ll.push_back(3);
   ll.push_back(2);
   ll.push_back(4);
   ll.push_back(5);
   ll.push_back(1);
   printList(ll.head);
   ll.head = mergeSort(ll.head);
   printList(ll.head);

   
    return 0;
}