#include <bits/stdc++.h> 

int f(vector<int> weight, vector<int> value , int n, int maxWeight, vector<vector<int>> &dp){

	//Check condition to end the itr
	if(n == 0){
		if(maxWeight >= weight[0]){
			dp[maxWeight][0] = value[0];
			return value[0];
		} 
		else {
			dp[maxWeight][0] = 0;
			return 0;
		}
	}
	if(maxWeight == 0) return 0;

	if(dp[maxWeight][n] != -1) return dp[maxWeight][n];
	//If Item is Included
	int Inc = -1;
	if(weight[n] <= maxWeight) Inc = f(weight, value, n-1, maxWeight - weight[n], dp) + value[n];

	//If Item is not Included
	int notInc = f(weight, value, n-1, maxWeight, dp);
	dp[maxWeight][n] = max(Inc, notInc);

	return max(Inc, notInc);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(maxWeight+1, vector<int>(n+1, -1));
	return f(weight, value, n-1, maxWeight, dp);
}

