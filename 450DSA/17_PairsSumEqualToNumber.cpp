#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	// Write your code here.

	int i=0;
	int j=n-1;
	int count = 0;

	while(i<j){
		if (arr[i] + arr[j] == target) {count++; i++; j--;}

		else if (arr[i] + arr[j] > target) j--;
		else i++;
		
	}
	if (count>0) return count;
	
	return -1;
}