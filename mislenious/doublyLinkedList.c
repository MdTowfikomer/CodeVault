#include <stdio.h>
#include <stdlib.h>
                    //  Doubly linked list
// create a list

// Insertion 
// -> insert at begin
// -> append
// -> inset at position

// deletion
// delete at begin
// delete at position
// delete at last

// print 

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node dNode;

dNode *head = NULL;
dNode *tail = NULL;

void createList(int val){
    dNode* newNode = NULL;
    newNode = (dNode*)malloc(sizeof(dNode));

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    head = tail = newNode;
}

void printList(){
    dNode* temp = head;
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

void appendNode(int val){
    // create a node first
    dNode* newNode = NULL;
    newNode = (dNode*)malloc(sizeof(dNode));

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL){
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insetAtBegin(int val){
    dNode* newNode = NULL;
    newNode = (dNode*)malloc(sizeof(dNode));

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL){
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode; // ← this was missing
    head = newNode;
}

void insertAtpostion(int val, int pos){
    if(pos <= 1){   // if position is less then or equals to 1
    insetAtBegin(val);
    return;
    }

    dNode* newNode = NULL;
    newNode = (dNode*)malloc(sizeof(dNode));

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    

    dNode* temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){ // if position is out of bound
        appendNode(val);
        return;
    }

    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}


void deleteAtbegin(void){
    if(head == NULL) return;

    dNode* collect = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    } else{
        tail = NULL;
    }
    free(collect);
    return;
}

void deleteAtEnd(void){
    if(tail == NULL) return;

    dNode* collect = tail;
    tail = tail->prev;

    if(tail != NULL)
    tail->next = NULL;
    else
    head = NULL;
    
    free(collect);
    return;
}

void deleteAtPosition(int pos){
    if(pos <= 1){
    deleteAtbegin();
    return;
}

    dNode* temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
    return;
    }

    dNode* collect = temp->next;
    temp->next = collect->next;
    if(collect->next != NULL)
    collect->next->prev = temp;
    else
    tail = temp;

    free(collect);
}

void midOfList(){
    dNode* slow = head;
    dNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("mid of the linked list is: %d", slow->data);
    return;
}



int main(){
    
    return 0;
}

