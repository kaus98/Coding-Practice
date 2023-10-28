#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure.
    
    class BinaryTreeNode {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*************************************************************/

vector<int> diagonalPath(BinaryTreeNode<int>* root) {
    // Write your code here.

    vector<int> result;
    queue<BinaryTreeNode<int>*> qu;
    if(root != NULL)  qu.push(root);

    BinaryTreeNode<int>* temp;
    while(!qu.empty()){
        temp = qu.front();
        qu.pop();

        result.push_back(temp->data);

        if(temp->left != NULL) qu.push(temp->left);

        while(temp->right != NULL){
            temp = temp->right;
            result.push_back(temp->data);
            if(temp->left != NULL) qu.push(temp->left);
        }

    }
    return result;

}