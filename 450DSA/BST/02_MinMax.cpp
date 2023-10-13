#include <bits/stdc++.h> 
/*
Structure of the Node of the BST is :

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
*/

int findPrice(Node* root)
{
    // Write your code here.
    if(root->left == NULL) return root->data;

    return findPrice(root->left);
}