#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minAbsoluteDifference(vector<int> A, vector<int> B){    // T.C = O(nlogn + nlogn + n) => O(nlogn)
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absoluteDiff = 0;
    for(int i =0 ; i < n; i++){
        absoluteDiff += abs(A[i]- B[i]);
    }

    return absoluteDiff;
}



int main(){
    vector <int> A = {1,10,4,4,2,7};
    vector <int> B = {9,3,5,1,7,4};

    cout << "Min Sum of Absolute difference is: " << minAbsoluteDifference(A, B) << endl;

    return 0;
}