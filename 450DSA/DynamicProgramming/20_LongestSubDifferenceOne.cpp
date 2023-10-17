#include <bits/stdc++.h> 
int longestSubsequence(vector<int> &nums){
	// Write your code here
	if(nums.size() == 1) return 1;

	vector<int> dp(nums.size(), 1);

	int maxi = 0;
	for(int i = 1; i < nums.size(); i++){
		for(int j = 0; j < i; j++){
			if(abs(nums[i] - nums[j]) == 1) {
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}

		maxi = max(maxi, dp[i]);
	}

	return maxi;
}