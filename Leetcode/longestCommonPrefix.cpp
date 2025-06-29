#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// topic: string and trie

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    string ans;
    sort(strs.begin(), strs.end());

    string first = strs[0], last = strs[n-1];

    int m = min(first.size(), last.size());
    for(int i = 0; i < m; i++){
        if(first[i] != last[i]){
            break;
        } 
        ans.push_back(first[i]);
    }

    return ans;
}
    
    
    int main(){
        vector<string> strs = {"flower","flow","flight"};
        vector<string> strs2 = {"dog","racecar","car"};

        cout << longestCommonPrefix(strs2) << endl;
        
    return 0;
}