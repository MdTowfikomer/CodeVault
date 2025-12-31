#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // row
        int n = matrix[0].size();

        for(int i= 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target1 = 3;
    int target2 = 13;

    cout << "Target " << target1 << " found: " << (searchMatrix(matrix, target1) ? "true" : "false") << endl;
    cout << "Target " << target2 << " found: " << (searchMatrix(matrix, target2) ? "true" : "false") << endl;

    return 0;
}