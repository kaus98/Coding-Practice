#include<bits/stdc++.h>

bool f(string a, string b, string c, int i, int j, int k, vector<vector<int>> &dp){

	//Both string A and B have ended but still left in the string
	if(i == a.length() && j==b.length()) {
		if(k == c.length()) return true;
		else return false;
	}

	if(dp[i][j] != -1) return dp[i][j];

	//Only A is finished But not B
	if(i == a.length() && k!=c.length()){
		if(b[j] == c[k]) return dp[i][j] = f(a, b, c, i, j+1, k+1, dp);
		else return false;
	}

	//Only B is finished But not A
	if(j == b.length() && k!=c.length()){
		if(a[i] == c[k]) return dp[i][j] = f(a, b, c, i+1, j, k+1, dp);
		else return false;
	}

	

	bool result = false;

	//Checking for a string 
	if(a[i] == c[k]) result = result || f(a, b, c, i+1, j, k+1, dp);

	if(b[j] == c[k]) result = result || f(a, b, c, i, j+1, k+1, dp);

	return dp[i][j] = result;
}

bool isInterleave(string a, string b, string c){
	//Your code goes here
	vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));
	return f(a, b, c, 0,0,0, dp);
}

