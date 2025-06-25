#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nums){
    idx++;
    if(nums[idx] == -1 || idx >= nums.size()){
        return NULL;
    }

    Node* curNode = new Node(nums[idx]);
    curNode->left = buildTree(nums);
    curNode->right = buildTree(nums);

    return curNode;

}


int main(){
    vector<int> nums = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nums);
    cout << "Root node data is " << root->data << endl;

    return 0;
}