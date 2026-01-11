#include <iostream>
#include <vector>
#include <algorithm>

// Function definition for threeSum
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i =0 ; i < n-2; i++){
            
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] > 0) break;

            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                } else if(sum < 0){
                    j++;
                } else{
                    k--;
                }
            }
        }
            return ans;
    }

void printResult(const std::vector<std::vector<int>>& result) {
    if (result.empty()) {
        std::cout << "[]";
        return;
    }
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << (j == result[i].size() - 1 ? "" : ",");
        }
        std::cout << "]" << (i == result.size() - 1 ? "" : ",");
    }
    std::cout << "]";
}

int main() {
    // Test Case 1
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::cout << "Test Case 1: Input = [-1, 0, 1, 2, -1, -4]\n";
    std::vector<std::vector<int>> result1 = threeSum(nums1);
    std::cout << "Output: ";
    printResult(result1);
    std::cout << "\nExpected: [[-1,-1,2],[-1,0,1]]\n\n";

    // Test Case 2
    std::vector<int> nums2 = {0, 1, 1};
    std::cout << "Test Case 2: Input = [0, 1, 1]\n";
    std::vector<std::vector<int>> result2 = threeSum(nums2);
    std::cout << "Output: ";
    printResult(result2);
    std::cout << "\nExpected: []\n\n";

    // Test Case 3
    std::vector<int> nums3 = {0, 0, 0};
    std::cout << "Test Case 3: Input = [0, 0, 0]\n";
    std::vector<std::vector<int>> result3 = threeSum(nums3);
    std::cout << "Output: ";
    printResult(result3);
    std::cout << "\nExpected: [[0,0,0]]\n\n";

    // Test Case 4
    std::vector<int> nums4 = {-2, 0, 1, 1, 2};
    std::cout << "Test Case 4: Input = [-2, 0, 1, 1, 2]\n";
    std::vector<std::vector<int>> result4 = threeSum(nums4);
    std::cout << "Output: ";
    printResult(result4);
    std::cout << "\nExpected: [[-2,0,2],[-2,1,1]]\n\n";

    // Test Case 5
    std::vector<int> nums5 = {};
    std::cout << "Test Case 5: Input = []\n";
    std::vector<std::vector<int>> result5 = threeSum(nums5);
    std::cout << "Output: ";
    printResult(result5);
    std::cout << "\nExpected: []\n\n";

    // Test Case 6
    std::vector<int> nums6 = {-1, 0, 1};
    std::cout << "Test Case 6: Input = [-1, 0, 1]\n";
    std::vector<std::vector<int>> result6 = threeSum(nums6);
    std::cout << "Output: ";
    printResult(result6);
    std::cout << "\nExpected: [[-1,0,1]]\n\n";

    return 0;
}