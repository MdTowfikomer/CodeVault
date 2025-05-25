#include <iostream>
#include <list>
#include <iterator> // to traverse LL
using namespace std;



void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout << (*itr) << "->";
    }
    cout << endl;
    return;
}

int main(){
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1); //1->2

    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);//1->2->3->4->5->


    printList(ll);
   
    return 0;
}