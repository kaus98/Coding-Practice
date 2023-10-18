#include <bits/stdc++.h> 
/* 
	Examcentre class

	template <typename T = int>
	class Examcentre {
		public:
			T data;
			Examcentre<T> *left;
			Examcentre<T> *right;

			Examcentre(T data)
			{
				this->data = data;
				left = NULL;
				right = NULL;
			}
	}
*/

// This is wrong Method
// I missunderstood the question

int f(Examcentre<int> *root , bool last, map<pair<Examcentre<int>*, bool>, int> &mp){

	if(root == NULL) return 0;
	if(mp.find({root, last}) != mp.end())  return mp[{root,last}];
	if(last == true){
		return mp[{root,last}] = f(root->left, false, mp)+f(root->right, false, mp);
	}
	else{
		return mp[{root,last}] = max(f(root->left, false, mp) + f(root->right, false, mp), 1+f(root->left, true, mp)+f(root->right, true, mp));
	}


}
int examInstructor(Examcentre<int> *root) {
	map<pair<Examcentre<int> *, bool>, int> mp;

	return max( f(root, true, mp), f(root, false, mp));
}


int examInstructor2(Examcentre<int> *root) {
	// Write your code here.

	queue<Examcentre<int> *> qu;

	qu.push(root);
	vector<int> result;
	Examcentre<int> *temp;
	result.push_back(1);
	int count = 1;

	while(!qu.empty()){
		while(count>0){
			temp = qu.front();
			if(temp->left != NULL) qu.push(temp->left);
			if(temp->right != NULL) qu.push(temp->right);
			qu.pop();
			count--;
		}
		
		count = qu.size();
		result.push_back(count);
		
	}

	cout<<"Checking :: "<<endl;
	for(auto x: result) cout<<x<<"\t";
	return 0;
}
