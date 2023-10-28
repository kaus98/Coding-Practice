/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void Order(TreeNode *root, vector<int> &result, int order){
    if(!root) return;
    
    if(order==0)result.push_back(root->data); // Preorder
    Order(root->left, result, order);
    if(order==1)result.push_back(root->data); // Inorder
    Order(root->right, result, order);
    if(order==2)result.push_back(root->data); // Postorder
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> res;
    vector<vector<int>> result;

    Order(root, res, 1);
    result.push_back(res);
    res.clear();
    Order(root, res, 0);
    result.push_back(res);
    res.clear();
    Order(root, res, 2);
    result.push_back(res);

    return result;

}

