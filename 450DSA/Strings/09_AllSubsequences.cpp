#include <bits/stdc++.h> 

void solve(string &str, string &temp, int node, vector<string> &result){
	if(node == str.size()) {
		if(temp != "") result.push_back(temp); 
		return;
	}

	temp.push_back(str[node]);
	solve(str, temp, node+1, result);
	temp.pop_back();
	solve(str, temp, node+1, result);
}

vector<string> subsequences(string str){
	
	// Write your code here
	int i = 0;
	string temp = "";
	vector<string> retu;

	solve(str, temp, 0, retu);

	return retu;
}

