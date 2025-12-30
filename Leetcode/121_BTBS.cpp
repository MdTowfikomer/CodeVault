#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    if (prices.empty()) {
        return 0;
    }
    int bestBuy = prices[0];

    for(size_t i = 0; i < prices.size(); i++){
        if(prices[i] > bestBuy){
        maxProfit = max(maxProfit, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }   
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max profit: " << maxProfit(prices) << endl;
    return 0;
}
