#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

void Inorder(TreeNode<int>* root, int k, vector<int> &result){
    if(root == NULL) return ;

    Inorder(root->right, k, result);

    result.push_back(root->data);
    if(k == result.size()) return;
    Inorder(root->left, k, result);
    
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int> result;
    Inorder(root, k, result);
    
    if(result.size() < k) return -1;
    return result[k-1];

}
