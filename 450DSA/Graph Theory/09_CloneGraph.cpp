#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode *solve(graphNode *node, unordered_map<graphNode* , graphNode*> &mp){
	graphNode *newNode = new graphNode(node->data);

	//Map to hold reference from original to new Graph
	mp[node] = newNode;

	vector<graphNode*> v;

	for(auto x: node->neighbours){
		if(mp.find(x) != mp.end()){
			v.push_back(mp[x]);
		} else{
			v.push_back(solve(x, mp));
		}
	}

	newNode->neighbours = v;
	return newNode;

}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	unordered_map<graphNode* , graphNode*> mp;

	return solve(node, mp);

}