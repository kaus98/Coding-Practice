#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void kSum(TreeNode<int> *root, int k, vector<int> &result, int &count){
    if(!root) return;

    result.push_back(root->data);
    
    int sum = 0;
    for(int i = result.size()-1; i >= 0; i--){
        sum+= result[i];
        if (sum==k) count++;
    }

    kSum(root->left, k, result, count);
    kSum(root->right, k, result, count);
    result.pop_back();

}

int noWays(TreeNode < int > * root, int k) {
    // Write your code here.

    vector<int> result;
    int count = 0;
    kSum(root, k, result, count);
    return count;
}
