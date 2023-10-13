#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode<T> *next;

	    TreeNode(T data)
	    {
		    this->data = data;
		    left = NULL;
		    right = NULL;
		    next=NULL;
	    }
    };

************************************************************/

void Next(TreeNode<int>*root, TreeNode<int>* &next){
    if(root == NULL) return;

    Next(root->right, next);
    root->next = next;
    next = root;
    Next(root->left, next);

}
void inorderSuccessor(TreeNode<int> *root)
{
	//    Write your code here
    TreeNode<int> * next = NULL;
    Next(root, next);
}