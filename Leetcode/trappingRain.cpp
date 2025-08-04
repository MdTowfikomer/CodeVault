#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int L[n], R[n];
    
    R[n-1] = INT_MIN, L[0]= INT_MIN;

    // L-max
    for(int i = 1; i < n; i++){
        L[i] = max(L[i-1], height[i-1]);
    }

    // R-max
    for(int i = n-2; i >= 0; i--){
        R[i] = max(R[i+1], height[i+1]);
    }
// printing L and R maxs
    // for(int i = 0; i < n; i++){
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << R[i] << " ";
    // }

    int waterTrap = 0;
    // select the lowest max-heigh of particular rode
    for(int i = 1; i < n-1; i++){
        int lowHeight = min(L[i], R[i]);
        // cout << lowHeight << " ";
        if(lowHeight > height[i]){
            waterTrap += lowHeight - height[i];
        }
    }

    return waterTrap;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "The amount of water trapped is: " <<  trap(height) << endl;
    // trap(height);

    return 0;
}