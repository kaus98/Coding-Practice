/*************************************************************

    Following is the Binary Tree node structure:

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

void InOrder(TreeNode* root, vector<int> &result){
    if(root == NULL) return;

    InOrder(root->left, result);
    result.push_back(root->data);
    InOrder(root->right, result);

}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> a,b,c;
    InOrder(root1, a);    
    InOrder(root2, b);


    int i = 0, j = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }

    while(i < a.size())  c.push_back(a[i++]);
    while(j < b.size())  c.push_back(b[j++]);

    return c;

}