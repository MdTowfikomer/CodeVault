#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
       std::vector<int> ans;
       for(size_t i = 0; i < nums.size(); i++){
            int temp = nums[i];
            for(int j = 1; j < nums[i]; j++){
                if( (j | (j+1)) == nums[i]){
                    temp = j;
                    break;
                }
            }
            if(temp == nums[i]){
                ans.push_back(-1);
                continue;
            } 
            ans.push_back(temp);
       }
       return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 7, 15};
    std::vector<int> result = solution.minBitwiseArray(nums);
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}