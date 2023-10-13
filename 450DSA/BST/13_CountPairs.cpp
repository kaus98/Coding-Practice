#include <bits/stdc++.h> 
/*Structure of the Node of the BST is as
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
*/



void InOrder(Node* root, vector<int> &result){
    if(root == NULL) return;

    InOrder(root->left, result);
    result.push_back(root->data);
    InOrder(root->right, result);

}



int countCouples(Node* root1, Node* root2 , int x)
{
    //Write your code here.
    vector<int> a,b;
    InOrder(root1, a);
    InOrder(root2, b);

    int count = 0;
    int j = b.size()-1;

    for(int i = 0; i <a.size(); i++){
        int temp = x - a[i];
        while(j>-1 && b[j]>temp)j--;
        if(j==-1) return count;
        if(b[j] == temp){count++; j--;}
    }

    return count;
}