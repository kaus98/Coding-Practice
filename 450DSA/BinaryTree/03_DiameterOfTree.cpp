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

int solve(TreeNode<int> *root, int &result){
    if(root == NULL) return 0;

    int left = solve(root->left, result);
    int right = solve(root->right, result);

    result = max(result, left + right );

    return max(left, right)+1;
}

int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    
    int result = -1;
    int temp = solve(root, result);

    return result;
}
