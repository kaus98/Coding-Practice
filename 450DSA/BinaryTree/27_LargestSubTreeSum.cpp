#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

long long treeSum(BinaryTreeNode<int> *root, long long &maxSum){
    if(!root) return 0;
    if(root->left == NULL && root->right == NULL){
        if(root->data > maxSum) maxSum = root->data; 
        return root->data;
    }
    
    long long leftH = treeSum(root->left, maxSum);
    long long rightH = treeSum(root->right, maxSum);

    // maxSum = max({maxSum, leftH+rightH+root->data});
    long long curH = leftH+rightH+root->data;
    if(maxSum < curH) maxSum = curH;
    return curH;

}

long long maxSubtreeSum(BinaryTreeNode<int> *root){
	// Write your code here.

    if(!root) return 0;

    long long result = INT_MIN+1;
    long long s1 = treeSum(root, result);

    // return (result);
    if(s1>result) return s1;
    return result;
}


