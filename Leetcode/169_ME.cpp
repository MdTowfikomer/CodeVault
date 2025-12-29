#include <iostream>
#include <vector>

using namespace std;


int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        int freq = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == max){
                freq++;
            } else{
                freq--;
            }

            if(freq <= 0){
                max = nums[i];
                freq = 1;
            }
        }

        return max;
    }

int main() {
    // Test case 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Majority Element in {3, 2, 3}: " << majorityElement(nums1) << endl; // Expected: 3

    // Test case 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element in {2, 2, 1, 1, 1, 2, 2}: " << majorityElement(nums2) << endl; // Expected: 2

    // Test case 3 (if the current solution handles it, this algorithm assumes a majority element always exists)
    // The Boyer-Moore Voting Algorithm correctly finds the majority element
    // if one exists. If no majority element exists, it will return one of the elements,
    // but not necessarily one that appears > n/2 times. The LeetCode problem guarantees
    // that a majority element always exists.
    vector<int> nums3 = {6, 5, 5};
    cout << "Majority Element in {6, 5, 5}: " << majorityElement(nums3) << endl; // Expected: 5

    return 0;
}