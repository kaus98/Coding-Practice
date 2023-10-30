#include <bits/stdc++.h> 
/*Structure of the Node of the Binary Tree is
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

int maxH(Node *root){
    if(root == NULL) return 0;

    return max(maxH(root->left), maxH(root->right)) + 1;
}

void maxHei(Node *root, int maxHe, int sum, int height, int &maxSum){
    if(root==NULL) {
        if(height == maxHe) maxSum = max(maxSum, sum);
        return;
    }

    maxHei(root->left, maxHe, sum+root->data, height+1, maxSum);
    maxHei(root->right, maxHe, sum+root->data, height+1, maxSum);

}

int longestPath(Node *root)
{
    //Write your code here.
    int maxHe = maxH(root);

    int maxSum = -1;

    maxHei(root, maxHe,  0, 0, maxSum);

    return maxSum;

}