#include <bits/stdc++.h> 

// Numberof  Tailing Zeroes in N! -> 
// Count = N/5 + N/25 + N/125 + N/625 .....
int countZeroes(int N){

	int count = 0, div = 5;

	while(div <= N){
		count += floor(N/div);
		div*=5;
	}
	// cout<<" --> For :: "<<N<<" :: "<<count<<endl;
	return count;
}
int findSmallestNumber(int n)
{
	// Write your code here.	q
	int start = 0, end = n, mid, ans = -1;

	while(start <= end){
		mid = start + (end-start)/2;

		// cout<<" -> "<<start<<" :: "<<mid <<" :: "<<end<<endl;
		if(countZeroes(mid*5) >= n){
			ans = mid;
			end = mid-1;

		} else {			
			start = mid+1;

		}
	}
	return ans*5;
}