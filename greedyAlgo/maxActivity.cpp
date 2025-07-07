#include <iostream>
#include <vector>
#include <algorithm>
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

bool compare(pair<int, int>& p1, pair<int, int>& p2){
    return p1.second < p2.second;
}



int main(){
    // vector<int> start = {1,3,0,5,8,5};
    // vector<int> end = {2,4,6,7,9,9};

    // cout << maxActivities(start, end) << endl;

    vector<int> start = {0,1,3};
    vector<int> end = {9,2,4};

    vector<pair<int, int>> activity(3, make_pair(0, 0));
    activity[0] = make_pair(0,9);
    activity[1] = make_pair(1,2);
    activity[2] = make_pair(3,4);

    for(int i = 0; i < activity.size(); i++){
        cout << activity[i].first <<","<<  activity[i].second << endl;
    }

    sort(activity.begin(), activity.end(), compare);

    cout << "After sorting...\n";

    for(int i = 0; i < activity.size(); i++){
        cout << activity[i].first <<","<<  activity[i].second << endl;
    }

    return 0;
}