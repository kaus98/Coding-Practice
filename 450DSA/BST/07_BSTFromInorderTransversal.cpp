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

TreeNode* f(vector<int> &o, int start, int end){
    if(start > end) return NULL;


    TreeNode* root = new TreeNode(o[start]);

    int i = start+1;

    while(i <= end){
        if(o[start] < o[i]) break;
        i++;
    }

    root->left = f(o, start+1, i-1);
    root->right = f(o, i, end);

    return root;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    return f(preOrder, 0, preOrder.size()-1);
}