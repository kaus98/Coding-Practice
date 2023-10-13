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

//Create a Inorder Transversal

void InorderTransversal(BinaryTreeNode<int> *root, vector<int> &order){
    if(root == NULL) return;

    InorderTransversal(root->left, order);
    order.push_back(root->data);
    InorderTransversal(root->right, order);
    return;
}


bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int> order;

    InorderTransversal(root, order);

    for(int i = 1; i < order.size(); i++){
        if(order[i] < order[i-1]) return false;
    }

    return true;
}