#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void InOrder(TreeNode<int>* root, int &result){
    if(root == NULL) return;

    InOrder(root->left, result);
    result++;
    InOrder(root->right, result);

}

void MedianOdd(TreeNode<int>* root, int &count, int &ans){
    if(root==NULL) return;

    MedianOdd(root->left, count, ans);
    count--;
    if(count == 0) {
        ans = root->data; 
        return;
    }
    MedianOdd(root->right, count, ans);
}

void MedianEven(TreeNode<int> *root, int &count, int &ans){
    if(root==NULL) return;

    MedianEven(root->left, count, ans);
    count--;
    if(count == 0 || count == 1) {
        ans += root->data; 
    }
    if(count== 0) return;
    MedianEven(root->right, count, ans);
}


int medianBST(TreeNode<int>* root) 
{
    // Write your code here.

    int count = 0;
    InOrder(root, count);
    int ans = 0;

    int temp = count+1;
    temp/=2;
    
    if(count%2 == 1){
        temp = (count+1)/2;
        MedianOdd( root, temp, ans);
        return ans;
    } else {
        temp = (count+2)/2;
        MedianEven(root, temp, ans);
        return ans/2;
    }
}
