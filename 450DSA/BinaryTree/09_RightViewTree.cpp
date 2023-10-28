/*************************************************************
 
    Following is the Binary Tree node structure:

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
    };

*************************************************************/

void rightView(BinaryTreeNode<int> *root, vector<int> &ans, int level){
    if (!root) return;

    if(level == ans.size()) ans.push_back(root->data);
    rightView(root->right, ans, level+1);
    rightView(root->left, ans, level+1);
}


vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> result;
    rightView(root, result, 0);
    return result;
}