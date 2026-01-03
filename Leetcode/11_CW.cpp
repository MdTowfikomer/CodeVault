 #include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int maxWater = INT_MIN;
        int breath = 0, length = 0;
        while(i < j){
            breath = j-i;
            length = min(height[i], height[j]);
            int curWater = breath * length;
            maxWater = max(maxWater, curWater);
            height[i] < height[j] ? i++ : j--;
        }
        return maxWater;
    }

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area is: " << maxArea(height) << endl;
    return 0;
}