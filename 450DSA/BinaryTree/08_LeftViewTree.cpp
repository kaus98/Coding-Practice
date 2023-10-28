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
void leftView(TreeNode<int> *root, vector<int> &ans, int level){
    if (!root) return;

    if(level == ans.size()) ans.push_back(root->data);
    leftView(root->left, ans, level+1);
    leftView(root->right, ans, level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> result;
    leftView(root, result, 0);
    return result;
}

