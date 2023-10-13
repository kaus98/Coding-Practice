#include <bits/stdc++.h> 
/*
template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

*/

int solve(pair<int, int>q, vector<int> v){
    int i = upper_bound(v.begin(), v.end(), q.second) - v.begin();
    int j = lower_bound(v.begin(), v.end(), q.first) - v.begin();

    return i-j;
}
void InOrder(BinaryTreeNode<int> *root, vector<int> &result){
    if(root == NULL) return;

    InOrder(root->left, result);
    result.push_back(root->data);
    InOrder(root->right, result);

}
vector<int> bstQueries(BinaryTreeNode<int> *root, int q, vector<pair<int, int>> queries) {
	// Write your code here.

    vector<int> ans;
    vector<int> result;

    if(root==NULL || q==0)
    {
        vector<int> ans;
        ans.push_back(0);
        return ans;
    }

    InOrder(root, result);

    for(int i = 0; i < q; i++){
        ans.push_back(solve(queries[i], result));
    }

    return ans;


}