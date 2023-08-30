#include <bits/stdc++.h> 
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	// Write Your Code here.

	unordered_set<int> uset;
	map<int,int> umap;

	for(int i = 0; i < arr1.size(); i++){
		uset.insert(arr1[i]);
		umap[arr1[i]]++;
	}
	int cnt = 0;
	for(int i = 0; i < arr2.size(); i++){
		uset.insert(arr2[i]);
		if(umap[arr2[i]] > 0) cnt++;
		//umap[arr2[i]]++;
	}
	pair<int, int> p = make_pair(cnt, uset.size());
	return p;


}
