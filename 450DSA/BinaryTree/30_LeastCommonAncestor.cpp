#include <bits/stdc++.h> 
/****************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*****************************************************************/


BinaryTreeNode<int>* findLCA(BinaryTreeNode<int>* root, BinaryTreeNode<int>* u, BinaryTreeNode<int>* v) {
    // Write your code here.

    if(!root) return NULL;
    if(u == NULL || v == NULL) return NULL;
    if(root == u || root == v) return root;

    BinaryTreeNode<int>* leftH = findLCA(root->left, u, v);
    BinaryTreeNode<int>* rightH = findLCA(root->right, u, v);
    
    if(leftH != NULL && rightH != NULL) return root;
    if(leftH == NULL && rightH != NULL) return rightH;
    if(leftH != NULL && rightH == NULL) return leftH;

    return NULL;
    
} 