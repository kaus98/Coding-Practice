/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/



int check(TreeNode <int> * root, bool &result){
    if(root == NULL) return 0;

    if(result) return 0;
    int left = check(root->left, result);

    if(result) return 0;
    int right = check(root->right, result);

    if(abs(left - right) > 1) result = true;
    return max(left, right)+1;
}

bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.

    bool result = false;
    int temp = check(root, result);

    return !result;

}