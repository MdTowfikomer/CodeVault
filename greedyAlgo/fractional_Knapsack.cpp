#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first;
}

int fractionalKnapsack(vector<int> value, vector<int> weight, int W){
    int n = value.size();
    // ratio, index
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0));
    for(int i = 0; i < n; i++){
       double r = value[i]/(double)weight[i];
       ratio[i] = make_pair(r, i); // pushing the ratio with their respective index
    }
    sort(ratio.begin(), ratio.end(), compare); // sorting in decending order to get max values item first

    int ans = 0;
    for(int i = 0; i < ratio.size(); i++){
        int idx = ratio[i].second;
        if(weight[idx] <= W){
            ans += value[idx];
            W -= weight[idx  ];
        } else{
            ans += W * ratio[i].first;
            W = 0;
            break;
        }
    }
    return ans;
}




int main(){
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20 , 30};
    int capacity = 50;


    cout << fractionalKnapsack(value, weight, capacity) << endl;
    return 0;
}