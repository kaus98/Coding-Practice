#include <bits/stdc++.h> 

// Recursion formula using Map
int fmp(vector<int> &arr, int n, int k, int i, int j,map<pair<int, int>, int> &mp){

	if(i>=j) return 0;
	if(arr[j] - arr[i] <= k) return 0;
	if(mp.find({i,j}) != mp.end()) return mp[{i,j}];

	return mp[{i,j}] = 1+min(fmp(arr, n, k, i+1, j, mp) , fmp(arr, n, k, i, j-1, mp));
}

// Recursion Formula using Vector
int fdp(vector<int> &arr, int n, int k, int i, int j, vector<vector<int>> &dp){

	if(i>=j) return 0;
	if(arr[j] - arr[i] <= k) return 0;
	if(dp[i][j]!= -1) return dp[i][j];

	return dp[i][j] = 1+min(fdp(arr, n, k, i+1, j, dp) , fdp(arr, n, k, i, j-1, dp));
}
//Just checking if Map can work faster than vector
//Both of them are working fine
// But only passing 10/11 test cases

//Using 1-D Array to check smallest 
int f1d(vector<int> &arr, int n, int k){
	
	vector<int> dp(n, 0);

	int i = 0;
	int j = 1;

	while(j<n){
		//Check if they can be made into pair of Min and Max
		if((arr[j] - arr[i]) <= k){
			dp[j] = i;
		}else{
			j--;
			i++;
		}
		j++;
	}
	int ma = INT_MAX-1;

	for(int j = 0; j < dp.size(); j++){
		ma = min(ma, n - (j-dp[j]+1));

	}
	// cout<<"1D Array :: "<<endl;
	// for(auto x: dp) cout<<x<<"\t";
	// cout<<endl;
	// cout<<"MA  came as :: "<<ma<<endl;

	return ma;
}
int minRemovals(vector<int>& arr, int n, int k)
{
	// Write your code here.
	

	sort(arr.begin(), arr.end());
	
	// map<pair<int, int>, int> mp;
	// return fmp(arr, n, k, 0, n-1, mp);

	// vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	// return fdp(arr, n, k, 0, n-1, dp);

	return f1d(arr, n, k);
}

