#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

void make(BinaryTreeNode<int> * root, vector<int> &arr, int &i){
    if(root == NULL) return;

    make(root->left, arr, i);
    root->data = arr[i++];
    make(root->right, arr, i);
}


void bst(BinaryTreeNode<int> * root, vector<int> &arr){
    if(root == NULL) return;

    bst(root->left, arr);
    arr.push_back(root->data);
    bst(root->right, arr);
}

BinaryTreeNode<int>* binaryTreeToBst(BinaryTreeNode<int>* root)
{
    // Write your code here
    vector<int> result;
    bst(root, result);
    sort(result.begin(), result.end());
    int i = 0;
    make(root, result, i);

    return root;
}
