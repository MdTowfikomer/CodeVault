#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    int ans = nums[0];
    for(int i = 1; i < n; i++){
       ans = ans^nums[i];
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The single number is: " << singleNumber(nums) << endl;
    return 0;
}
