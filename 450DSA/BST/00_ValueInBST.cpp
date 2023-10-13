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

bool findNode(TreeNode <int> * root, int key) {
    // Write your code here.
    if(root == NULL ) return false;

    if(root->data == key) return true;
    
    //Look in right side
    if(root->data < key){
        return findNode(root->right, key);
    }

    //Look in left Side
    if(root->data > key){
        return findNode(root->left, key);
    }
}