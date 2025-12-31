#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int curSum = 0;

        for(int i =0 ; i < n; i++){
        curSum += nums[i];
        maxSum = max(maxSum, curSum);
        if(curSum < 0){
            curSum = 0;
        }
        }
        return maxSum;
    }

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum is: " << maxSubArray(nums) << endl;
    return 0;
}