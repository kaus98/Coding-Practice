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

int Kth(BinaryTreeNode<int> *root, int targetNodeVal, int k, int &result){
    if(!root) return NULL;

    if(root->data == targetNodeVal) return 1;

    int leftH = Kth(root->left, targetNodeVal, k, result);
    int rightH = Kth(root->right, targetNodeVal, k, result);

    if(leftH == NULL && rightH == NULL) return NULL;
    int he;
    if(leftH == NULL) he = rightH;
    else he = leftH;

    if (he == k) result = root->data;
    return he+1;    
}

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    // Write your code here.
    int result = -1;

    Kth(root, targetNodeVal, k, result);

    return result;
}

