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


void solve(TreeNode<int> *root, TreeNode<int> *&prev, TreeNode<int> *&head){
    if(root==NULL) return;

    solve(root->left, prev, head);

    if(head == NULL) head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    solve(root->right, prev, head);

    // return head;
}

TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
	// Write your code here.
    TreeNode<int> *head = NULL, *prev = NULL;
    solve(root, prev, head);
    return head;    
}