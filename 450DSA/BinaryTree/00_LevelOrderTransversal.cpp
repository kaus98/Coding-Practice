#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> result;

    queue<BinaryTreeNode<int>*> que;

    que.push(root);
    while(!que.empty()){
        BinaryTreeNode<int>*t = que.front();

        result.push_back(t->val);
        if(t->left != NULL) que.push(t->left);
        if(t->right != NULL) que.push(t->right);
        que.pop();
    }
    return result;
}