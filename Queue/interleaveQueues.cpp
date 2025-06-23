#include <iostream>
#include <queue>
using namespace std;
// To solve this problem first we need to add half element of the queue to the auxilary queue.
// then till the auxilary queue is not empty 
// first we push the element of aux queue then the og queue element till the above condition is true
// Hence we will get the interleave queue

void interleaveQueue(queue<int> &oG){
    queue<int> aux;
    int n = oG.size();
    
    for(int i = 0; i < n/2; i++){
        aux.push(oG.front());
        oG.pop();
    }

    while(!aux.empty()){
        oG.push(aux.front());
        aux.pop();

        oG.push(oG.front());
        oG.pop();
    }
}
 
int main(){
    queue<int> og;
    for(int i = 0; i < 10; i++){
        og.push(i+1);
    }

    interleaveQueue(og);

   while(!og.empty()){
    cout << og.front() << " ";
    og.pop();
   }

   return 0;
}