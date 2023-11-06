#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/

void inOrder(BinaryTreeNode* root, vector<int> &ans){
	if(root == NULL) return;

	inOrder(root->left, ans);
	ans.push_back(root->data);
	inOrder(root->right, ans);

}

void preOrder(BinaryTreeNode* root, vector<int> &ans, int &index){
	if(root == NULL) return;

	root->data = ans[index++];
	preOrder(root->left, ans, index);
	preOrder(root->right, ans, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.

	vector<int> ans;
	inOrder(root, ans);
	int index = 0;
	preOrder(root, ans, index);

	return root;
}