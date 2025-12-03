#include <iostream>
using namespace std;

int subArrayLen(int arr[], int n, int k){
    int length = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum <= k){
                length = max(length, j-i+1);
            } else if(sum > k){
                break;
            }
        }
    }
    return length;
}

int main(){
    int nums[] = {2,5,1,7,10};
    int n = sizeof(nums)/sizeof(int);
    int k = 14;

    cout << subArrayLen(nums, n, k) << endl;

    return 0;
}