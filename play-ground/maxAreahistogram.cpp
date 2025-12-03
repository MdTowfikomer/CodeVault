#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

void printArrayI(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}


int maxHistogram(vector<int>& heights){
    int n = heights.size();
   stack<int> sl;
   stack<int> sr;
   vector<int> nsl(n);
   vector<int> nsr(n);
   // next smaller left
   nsl[0] = n;
   sl.push(0);
   for(int i = 1; i<n; i++){
    int cur = heights[i];          // previous
       while(!sl.empty() && cur <= heights[sl.top()] ){ // if the previous element is greater than the current pop 
        sl.pop();
       }
       if(sl.empty()){
        nsl[i] = n;
       } else{
        nsl[i] = sl.top(); // stack top index
       }
       sl.push(i);   // pushing the index of the current element into the stack
    }

    // next smaller right
    nsr[n-1] = n;
    sr.push(n-1);
    for(int i = n-2; i >= 0; i--){
        int cur = heights[i];
        while(!sr.empty() && cur <= heights[sr.top()]) { // if the previous element is greater than current pop
            sr.pop();
        }
        if(sr.empty()){
            nsr[i] = n;
        } else{
            nsr[i] = sr.top();
        }
        sr.push(i);
    }

    int maxArea = INT_MIN;  
    for(int i = 0; i < n; i++){
        int width = nsr[i] - nsl[i] - 1; // r - l - 1
        int area = heights[i] * width;
        maxArea = max(area, maxArea);
    }

    cout << "max area of the histogram is : ";
    return maxArea;
   
}



int main(){
    vector<int> heights = {2,1,5,6,2,3};

    cout << maxHistogram(heights) << endl;

    return 0;
}