#include <bits/stdc++.h> 
/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class TreeNode {
    public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
long long enc(int val){
    // return ((val*val*val)/43) + (((val%3)*(val-1)*(val+5)*(val+7))%31);
    return ((val%3) + val/13 + (val-6)) * val ;
}

bool anagram(TreeNode<int>*root1, int n, TreeNode<int>*root2, int m)
{
	// Write your code here


    queue<TreeNode<int>*> q1, q2;
    TreeNode<int>* tmp;
    q1.push(root1);
    q2.push(root2);

    long long s1, s2;

    while(!q1.empty() && !q2.empty() && q1.size() == q2.size()){
        s1 = 0;
        s2 = 0;

        int  n = q1.size();

        while(n--){
            tmp = q1.front();q1.pop();
            s1 += enc(tmp->val);
            if(tmp->left != NULL)q1.push(tmp->left);
            if(tmp->right != NULL)q1.push(tmp->right);


            tmp = q2.front();q2.pop();
            s2 += enc(tmp->val);
            if(tmp->left != NULL)q2.push(tmp->left);
            if(tmp->right != NULL)q2.push(tmp->right);

        }
        if(s1 != s2) return false;
    }
    if(!q1.empty() || !q2.empty()) return false;
    return true;
}