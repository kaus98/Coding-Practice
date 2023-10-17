#include <bits/stdc++.h> 

//First Solution can be solved using Sorting
//Perform better than 99% Solutions
int s(vector<int> &arr, int n, int k){
	sort(arr.begin(), arr.end());

	int N = n-2;
	int sum = 0;
	while(N >= 0){
		if((arr[N+1] - arr[N]) < k){
			sum += (arr[N+1] + arr[N]);
			N -= 2;
			// cout<<"Sum :: "<<sum<<" N :: "<<N;
		}
		else {
			N--;
		}
	}

	return sum;
}

// Second Solution is using array that saves upto N the Maximum Sum and the end element represent the Total Sum possible
// Perform better than 36%

int dp(vector<int> &arr, int N, int K){
	sort(arr.begin(), arr.end());

	vector<int> dp(arr.size()+1, 0);
	dp[1] = 0;

	for(int i = 2; i <= N; i++){
		if((arr[i-1] - arr[i-2]) < K){
			if(i==2){
				dp[i] = arr[i-2]+arr[i-1];
			}else{
				//Take the current and save to this element
				dp[i] = max(dp[i-1] , dp[i-2] + arr[i-2]+arr[i-1]);
			}
		}else{
			dp[i] = dp[i-1];
		}
	}
	return dp[N];
}

int maxSumPairWithDifferenceLessThanK(vector<int> & arr, int n, int k){
	// Write your code here.
	// return s(arr, n, k);
	return dp(arr, n, k);
}

