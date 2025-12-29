#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        int n = grid[0].size(); // cols
        int m = n * n;
        std::vector<int> freq(m, 0);
        std::vector<int> ans(2);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                freq[num - 1]++;
            }
        }

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 2) {
                ans[0] = i + 1;
            } else if (freq[i] == 0) {
                ans[1] = i + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1:
    std::vector<std::vector<int>> grid1 = {{1, 3}, {2, 2}};
    std::vector<int> result1 = sol.findMissingAndRepeatedValues(grid1);
    std::cout << "Repeated: " << result1[0] << ", Missing: " << result1[1] << std::endl; // Expected: Repeated: 2, Missing: 4

    // Example 2:
    std::vector<std::vector<int>> grid2 = {{9,1,7},{8,9,2},{3,4,6}};
    std::vector<int> result2 = sol.findMissingAndRepeatedValues(grid2);
    std::cout << "Repeated: " << result2[0] << ", Missing: " << result2[1] << std::endl; // Expected: Repeated: 9, Missing: 5


    return 0;
}