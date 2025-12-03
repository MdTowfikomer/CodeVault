// Sliding window understanding
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// int maxSum(int arr[], int n, int k){
//   // first find the sum till k-elements
//   int maxSum = 3456789;
//   int sum = 0;
//   for(int i = 0; i < k; i++){
//     sum += arr[i];
//     maxSum = sum;
//   }

//   // now slide the window
//   int l = 0;
//   int r = k-1;

//   while(r < n-1){
//     sum -= arr[l];
//     l++, r++;
//     sum += arr[r];
//     maxSum = max(sum, maxSum);
//   }
//   return maxSum;
// }



// int main(){
//   int nums[] = {-12,33,3,3,3,4,5,5,6,6,7,7,100,8,4,5,2,3,3,4,5,-1};
//   int n = sizeof(nums)/sizeof(int);
//   int k = 4;

//   cout << "The maxSum is: " << maxSum(nums, n, k) << endl;

//   return 0;
// }

int main(){
  char str = 'a';
  char demo = 'A';

  char test = (demo + 32);
  char test2 = (str - 32);
  cout << str << endl;
  cout << test << endl;
  cout << test2 << endl;
  // char test = (int)(demo + 32);

  if(str == test2){
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  return 0;
}