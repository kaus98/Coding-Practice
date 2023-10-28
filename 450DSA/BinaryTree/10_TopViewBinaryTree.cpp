/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    map<int, int> mp;

    queue<pair<TreeNode<int> *, int>> qu;
    
    qu.push({root, 0});

    while(!qu.empty()){
        auto q = qu.front();
        qu.pop();
        int v = q.second;
        TreeNode<int> * tp = q.first;

        if(mp.find(v) == mp.end()) mp[v] = tp->data;
        if(tp->left) qu.push({tp->left, v-1});
        if(tp->right) qu.push({tp->right, v+1});
    }

    vector<int> result;
    for(auto x: mp){
        result.push_back(x.second);
    }

    return result;
}
