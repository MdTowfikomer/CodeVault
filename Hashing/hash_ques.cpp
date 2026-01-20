#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2,12,2,11,-12,2,-1,2,2,11,12,2,-6};
    int n = sizeof(arr)/sizeof(int);

    unordered_map<int,int> mp;

    for(auto i: arr){
        mp[i]++;
    }
    int max = INT_MIN;
    int ans = -1;
    
    for(auto i: mp){
        if(i.second > max){
            max = i.second;
            ans = i.first;
        }
    }
    cout << "The maximum repeated key and value are " << ans << ":" << max << endl;
    return 0;
}