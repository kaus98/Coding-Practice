/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

BinaryTreeNode<int>* join(BinaryTreeNode<int>* root){
    //If both of right and left are None
    if(root->left == NULL && root->right == NULL) return NULL;

    if(root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;

    //We will look Greatest element in Left
    BinaryTreeNode<int>* leftChild = root->left;
    BinaryTreeNode<int>* rightChild = root->right;

    while(leftChild->right){
        leftChild = leftChild->right;
    }

    leftChild->right = rightChild;

    return root->left;
}


BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    // Write your code here.

    if(root == NULL) return root;

    if(root->data == key) return join(root);

    BinaryTreeNode<int>* temp = root;

    while(root){
        if(root->data > key){
            //Check if left node data is key
            if(root->left && root->left->data == key){
                root->left = join(root->left);
                break;

            }
            else root = root->left;
        } else{
            if(root->right && root->right->data == key){
                root->right = join(root->right);
                break;
            }
            else root = root->right;
        }
    }

    return temp;
}
