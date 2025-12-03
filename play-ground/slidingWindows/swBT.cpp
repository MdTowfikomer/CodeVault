#include <iostream>
using namespace std;

int betterApproach1(int arr[], int n, int k){
    int l = 0;
    int r = 0;
    int sum = 0, maxLen = 0;
    while(r < n){
        sum += arr[r];
        // cout << sum << " ";
        while(sum > k){
            sum -= arr[l];
            l++;
        }
        if(sum <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;    // expand
    }
    return maxLen;
}


int main(){
    int arr[] = {2,5,1,6,10};
    int n = sizeof(arr)/sizeof(int);
    int k = 14;
    cout << betterApproach1(arr, n, k);

    return 0;
}