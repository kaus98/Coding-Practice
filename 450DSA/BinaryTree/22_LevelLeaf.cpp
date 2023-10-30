#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
bool checkFlag(TreeNode<int> *root, int current, int &maxCur){
        if(!root) {
            return true;
        }
        
        if(root->left == NULL && root->right == NULL){
            if(maxCur == -1) maxCur = current;
            else if(maxCur != current) return false;
            return true;
        }
        
        return (checkFlag(root->left, current+1, maxCur) && checkFlag(root->right, current+1, maxCur));
    }

int levelLeaf(TreeNode<int> *root) {
    // Write your code here.
    bool result;
        int temp = -1;
        result = checkFlag(root, 0, temp);
        // return result;
    if(result) return 1;
    return 0; 
}

