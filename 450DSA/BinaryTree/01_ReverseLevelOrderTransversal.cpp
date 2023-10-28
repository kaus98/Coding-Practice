#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    vector<int> result;
    if(root == NULL) return result;
    queue<TreeNode<int>*> que;

    que.push(root);
    while(!que.empty()){
        TreeNode<int>*t = que.front();

        result.push_back(t->val);
        if(t->left != NULL) que.push(t->left);
        if(t->right != NULL) que.push(t->right);
        que.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}