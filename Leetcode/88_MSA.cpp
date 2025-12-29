#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = nums1.size() - 1;

        while (k >= 0) {
            if (j >= 0 && i >= 0 && nums2[j] >= nums1[i]) {
                nums1[k] = nums2[j--];
            } else if (i >= 0) {
                nums1[k] = nums1[i--];
            } else if (j >= 0) {
                nums1[k] = nums2[j--];
            }
            k--;
        }
    }
};

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;

    // Example 1
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;
    sol.merge(nums1, m, nums2, n);
    std::cout << "Merged array: ";
    printVector(nums1); // Expected output: 1 2 2 3 5 6

    // Example 2
    std::vector<int> nums1_2 = {1};
    int m_2 = 1;
    std::vector<int> nums2_2 = {};
    int n_2 = 0;
    sol.merge(nums1_2, m_2, nums2_2, n_2);
    std::cout << "Merged array: ";
    printVector(nums1_2); // Expected output: 1

    // Example 3
    std::vector<int> nums1_3 = {0};
    int m_3 = 0;
    std::vector<int> nums2_3 = {1};
    int n_3 = 1;
    sol.merge(nums1_3, m_3, nums2_3, n_3);
    std::cout << "Merged array: ";
    printVector(nums1_3); // Expected output: 1

    return 0;
}
