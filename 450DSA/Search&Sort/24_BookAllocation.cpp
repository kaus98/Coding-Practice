#include <bits/stdc++.h> 

bool isPossible(vector<int> time, int days, long long int mid){
	// cout<<"IS Possible :: "<<days<<" :: "<<mid<<endl;

	long long int act = 0;
	long long int day = 1;
	for(int i = 0; i < time.size(); i++){
		// if(time[i] > mid) return false;

		if((act+time[i]) <= mid){
			act+= time[i];
		} else {
			act = 0;
			day++;
			i--;
		}
		// cout<<"I :: "<<i<<" :: "<<act<<" :: "<<day<<endl;
		if(day > days) return false;
	}

	return true;

}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.

	long long int start = -1, end = 0, ans = -1, mid;

	for(auto x: time) {end += x; if(x > start) start = x;}


	while(start <= end){
		mid = start + (end - start)/2;
		// cout<<"Checking for :: "<<start<<" :: "<<end <<" :: "<<mid<<endl;
		if(isPossible(time, n, mid)){
			ans = mid;
			end = mid-1;
		} else {
			start = mid+1;

		}
	}

	return ans;
}