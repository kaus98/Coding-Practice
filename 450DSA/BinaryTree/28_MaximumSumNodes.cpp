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

int solve(TreeNode<int> *root, bool last, map<pair<TreeNode<int> *, bool>, int>  &dp){
    if(root == NULL) return 0;

    if(dp.find({root, last}) != dp.end()) return dp[{root, last}];
    int include = 0;
    int exclude = 0;

    //To Include
    //We can  only include if last one is not included
    if(last){
        include = solve(root->left, false, dp) + solve(root->right, false, dp) + root->data;
    }
    //To Exclude

    exclude = solve(root->left, true, dp) + solve(root->right, true, dp);

    return dp[{root, last}] = max(include, exclude);
}
int maximumSumOfNodes(TreeNode<int> *root)
{
	//    Write your code here

    map<pair<TreeNode<int> *, bool>, int> dp;
    return solve(root, true, dp);
}