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

vector<int> levelOrder(TreeNode<int> * root)
    {
    	// Code here
    	queue<TreeNode<int>*> p1;
    	queue<TreeNode<int>*> p2;
    	vector <int> result;
    	
    	p1.push(root);
    	TreeNode<int>* temp;
    	
    	while(!p1.empty() && !p2.empty()){
    	    if(!p1.empty()){
    	        while(!p1.empty()){
    	            temp = p1.front();
    	            result.push_back(temp->data);
    	            p2.push(temp->left);
    	            p2.push(temp->right);
    	            p1.pop();
    	        }
    	    }else{
    	        while(!p2.empty()){
    	            temp = p2.front();
    	            result.push_back(temp->data);
    	            p1.push(temp->left);
    	            p1.push(temp->right);
    	            p2.pop();
    	        }
    	    }
    	}
    	return result;
    }