#include <stdio.h>
// binary search

// Rule -1 for binary search is the given input should be sorted.

void binarySearch(int arr[], int n, int target){
    // first spillting the input in two parts
    int low = 0, high = n-1;

   while(low <= high){
        int mid = (low+high)/2;
        // comparing mid with target 
        if(arr[mid] > target){  // 3 > 2
            high = mid-1;
        } else if(arr[mid] < target){ // 3 < 6
            low = mid+1;
        } else {
            printf("%d is found at %d index\n", target, mid);
            return; // index of the target element
        }
    }
    printf("Element not found..\n");
    return;// not found
}

int main(){
    int n = 8;
    int arr[8] = {1,2,3,4,5,6,7,8};
    int target = 6;

    

    binarySearch(arr, n, target);

    return 0;
}
