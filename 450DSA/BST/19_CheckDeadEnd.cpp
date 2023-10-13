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

bool isDeadEnd(TreeNode<int>* root, int L = 1, int R = 1e9) {
    // Write your code here
    if(root==NULL) return false;

    if(root->left == NULL && root->right == NULL) return L==R;
    return isDeadEnd(root->left, L, root->data-1)|| isDeadEnd(root->right, root->data+1, R);
}