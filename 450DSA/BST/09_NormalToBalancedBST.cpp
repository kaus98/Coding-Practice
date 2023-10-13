/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

void InOrder(TreeNode<int>* root, vector<int> &result){
    if(root == NULL) return;

    InOrder(root->left, result);
    result.push_back(root->data);
    InOrder(root->right, result);

}

TreeNode<int>* b(int start, int end, vector<int> &result){
    if(start > end) return NULL;

    int mid = (start+end)/2;
    TreeNode<int>* temp = new TreeNode<int>(result[mid]);

    temp->left = b(start, mid-1, result);
    temp->right = b(mid+1, end, result);

    return temp;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> result;

    InOrder(root, result);

    root = b(0, result.size()-1, result);

    return root;


}
