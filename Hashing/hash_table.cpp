#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }

    ~Node() {
        if(next != nullptr){
            delete next;
        }
    }
};

class HashTable{
    int totalSize;
    int curSize;
    Node** table;
    
    int hashFunction(string key){
        int idx = 0;
        
        for(int i = 0; i < key.size(); i++){
            idx = idx + (key[i]*key[i]) % totalSize;
        }

        return idx % totalSize;
    }

    void rehash(){
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2*totalSize;
        curSize = 0;
        table = new Node*[totalSize];

        for(int i=0; i < totalSize; i++){
            table[i] = nullptr;
        }

        for(int i = 0; i < oldSize; i++){
          Node* temp = oldTable[i];
          while(temp != nullptr){
            insert(temp->key, temp->value);
            temp = temp->next;
          }

          if(oldTable[i] != nullptr){
            delete oldTable[i];
          }
        }

        delete[] oldTable;
    }


public:
    HashTable(int size) {
        totalSize = size;
        curSize = 0; // rehashing

        table = new Node*[totalSize];

        for(int i = 0; i < totalSize; i++){
            table[i] = nullptr;
        }
    }

    // insert operation
    void insert(string key, int val){
        int idx = hashFunction(key);
        
        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        curSize++;
        
        double lamda = curSize/(double)totalSize;

        if(lamda > 1){
            rehash();
        }
    }

    bool exist(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while(temp != nullptr){
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    int search(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        if(exist(key)){
            while(temp != nullptr){
                if(temp->key == key){
                    return temp->value;
                }
                temp = temp->next;
            }
        } 
        return -1;
    }

    void print_table(){
        for(int i = 0; i < totalSize; i++){
            cout << "idx: " << i << "->";
            Node* temp = table[i];
            while(temp != nullptr){
                cout << temp->key << ":" <<  temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void remove(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = temp;
        if(exist(key)){
            while(temp != nullptr){
                if(temp->key == key){
                    if(prev == temp){
                        table[idx] = temp->next;
                    } else{
                        prev->next = temp->next;
                    }
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }
};

int main(){
    HashTable h1(5);

    h1.insert("India", 150);
    h1.insert("china", 150);
    h1.insert("US", 50);
    h1.insert("Nepal", 10);
    h1.insert("UK", 20);

    h1.remove("china");
    h1.print_table();

    return 0;
}