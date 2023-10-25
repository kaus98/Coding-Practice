#include <bits/stdc++.h> 
int maximiseSum(vector<int>& arr1, vector<int>& arr2, int n, int m) {
	// Write your code here,

	long long int sum1 = 0, sum2 = 0, p1 = 0, p2 = 0;
	long long int ans = 0;
	while(p1 < n && p2 < m){
		if(arr1[p1] > arr2[p2]){
			sum2 += arr2[p2++];
		}

		else if(arr1[p1] < arr2[p2]){
			sum1 += arr1[p1++];
		}

		else {
			ans += max(sum1 , sum2);
			ans += arr1[p1];
			p1++;
			p2++;
			sum1 = 0;
			sum2 = 0;
		}
	}

	while(p1 < n){
		sum1 += arr1[p1++];
	}

	while(p2 < m){
		sum2 += arr2[p2++];
	}

	return ans + max(sum1, sum2);
}