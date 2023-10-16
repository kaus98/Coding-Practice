#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	if(n==1) return rack[0];

	vector<int> dp(n, 0);
	int maxSum = INT_MIN+1;
	// dp[0] = rack[0];
	for(int i = 0; i < n; i++){
		dp[i] = rack[i];
		maxSum = max(maxSum, rack[i]);

		for(int j = 0; j < i; j++){
			if(rack[j] < rack[i]){
				dp[i] = max(dp[j]+rack[i], dp[i]);
			}
		}

		maxSum = max(maxSum, dp[i]);
	}
	// cout<<"Updated DP is :: "<<endl;
	// for(int i = 0; i < n; i++){
	// 	cout<<dp[i]<<"\t";
	// }
	return maxSum;
}