#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void InOrder(TreeNode<int>* root, TreeNode<int> *&ans){
    if(root==NULL) return;

    InOrder(root->left, ans);
    ans->right = new TreeNode<int> (root->data);
    ans = ans->right;
    InOrder(root->right, ans);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> result;
    TreeNode<int> *ans = new TreeNode<int> (-1);
    TreeNode<int> *temp = ans;
    InOrder(root, ans);

    return temp->right;

    
}
