/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
//Not using here
int getMin(TreeNode *root){
    if(root->left == NULL) return root->data;
    return getMin(root->left);
}
//Not using here
int getMax(TreeNode *root){
    if(root->right == NULL) return root->data;
    return getMax(root->right);
}

void solve(TreeNode *root, int key, pair<int, int> &temp){
    if(root == NULL) return;

    if(root->data > temp.first && root->data < key)temp.first = root->data;
    if(root->data < temp.second && root->data > key)temp.second = root->data;
    
    solve(root->left, key, temp);
    solve(root->right, key, temp);
}

void searchTree(TreeNode *root, pair<int, int> &temp, int key){
    temp.first = INT_MIN;
    temp.second = INT_MAX;

    solve(root, key, temp);

    temp.first = (temp.first==INT_MIN)?-1:temp.first;
    temp.second = (temp.second==INT_MAX)?-1:temp.second;

}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    pair<int, int> temp;
    searchTree(root, temp, key);

    return temp;
}