#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> st, vector<int> end){
    // sort the end of the activities. (already done in the question)
    // 1st activity is always selected cause for sure it will end soon so as the end is sorted
    int count = 1; 
    int currentEnd = end[0];
    for(int i =1 ; i < st.size(); i++){
        if(currentEnd <= st[i]){
            count++;
            currentEnd = end[i];
        }
    }

    return count;
}



int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout << maxActivities(start, end) << endl;

    return 0;
}