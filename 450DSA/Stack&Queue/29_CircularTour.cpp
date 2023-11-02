#include <bits/stdc++.h> 
int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
{
	// write your code here

	int start = 0;
	long long neg = 0;
	long long balance = 0;
	for(int i = 0; i < N; i++){
		balance += petrol[i]-distance[i];

		if(balance < 0){
			neg += balance;
			start = i+1;
			balance = 0;
		}
	}

	if(neg + balance >= 0) return start;
	else return -1;
}
