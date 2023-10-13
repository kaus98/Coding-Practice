/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/
void Inorder(TreeNode<int>* root, int k, vector<int> &result){
    if(root == NULL) return ;

    Inorder(root->left, k, result);

    result.push_back(root->data);
    if(k == result.size()) return;
    Inorder(root->right, k, result);
    
}


int kthSmallest(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int> result;
    Inorder(root, k, result);
    
    if(result.size() < k) return -1;
    return result[k-1];

}

