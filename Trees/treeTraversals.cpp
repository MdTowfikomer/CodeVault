#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;
    // First building the tree from the given data
Node* buildTree(vector<int> nums){
    idx++;
    if(idx >= nums.size() || nums[idx] == -1){
        return nullptr;
    }
    
    Node* curNode = new Node(nums[idx]);
    curNode->left = buildTree(nums);
    curNode->right = buildTree(nums);

    return curNode;
}
// pre-Order traversal
// root -> left -> right
void preOrder(Node* root){
    if(root == nullptr){
        return;
    }

    cout << root->data << " ";  // root
    preOrder(root->left);       // left
    preOrder(root->right);      // right

}

// In-Order traversal
// left -> root -> right
void inOrder(Node* root){
    if(root == nullptr){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}
// Post-Order traversal
// left -> right -> root
void postOrder(Node* root){
    if(root == nullptr){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";

}

// level-Order traversal
void levelOrder(Node* root){
    if(root == nullptr){
        return;
    }
     
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node* curr = Q.front();
        Q.pop();
        cout << curr->data << " ";
        if(curr->left != nullptr){
            Q.push(curr->left);
        }
        if(curr->right != nullptr){
            Q.push(curr->right);
        }
    }

}

int main(){
    vector<int> nums = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nums);

    cout << "Pre-order traversal of the Tree is: ";
    preOrder(root);
    cout << endl;

    cout << "In-Order traversal of the Tree is: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal of the Tree is: ";
    postOrder(root);
    cout << endl;


    return 0;
}
 