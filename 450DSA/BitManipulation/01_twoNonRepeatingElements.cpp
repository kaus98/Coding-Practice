#include <bits/stdc++.h> 
vector<int> findNonRepeating(vector<int> a)
{
	// Write Your Code Here.

	int opr = 0,ans1=0,ans2=0;
	for(auto x: a) opr^=x;
	opr=opr&~(opr-1);
	for(auto x: a) 
		if(x&opr)ans1^=x;
		else ans2^=x;

	vector<int> ans;
	if(ans1 > ans2) {
		ans.push_back(ans2);
		ans.push_back(ans1);
	} else {
		ans.push_back(ans1);
		ans.push_back(ans2);
	}
	return ans;
}
