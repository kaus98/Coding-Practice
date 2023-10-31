bool checkTree(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2) 
{
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    bool left1 = checkTree(root1->left, root2->left);
    bool right1 = checkTree(root1->right, root2->right);
    bool left2 = checkTree(root1->left, root2->right);
    bool right2 = checkTree(root1->right, root2->left);

    return (left1 && right1) || (left2 && right2);
}