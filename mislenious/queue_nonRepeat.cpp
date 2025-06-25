#include <iostream>
#include <queue>
using namespace std;


char nonRepeatLetter(string str){
    queue<char> Q;  // to track the non-repeating letter
    int freq[26] = {0};   // to count the frequency of the letter

    for(int i = 0; i < str.size(); i++){
        int ch = str[i];
        freq[ch -'a']++;
        Q.push(ch);  // Enqueued the letter to the Q


        while(!Q.empty() && freq[Q.front() - 'a'] > 1){
            Q.pop();
        }
    }
    if(!Q.empty()){
        return Q.front();
    }
    return -1;
}


int main(){
    string ch = "aabccxb";
    cout << "Non repeating letter is :"<<   nonRepeatLetter(ch) << endl; 

    return 0;
}