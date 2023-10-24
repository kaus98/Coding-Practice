// Coding Ninda Similar Question
// https://www.codingninjas.com/studio/problems/chess-tournament_981299?

#include <bits/stdc++.h> 

bool isPossible(vector<int> pos, int n, int distance , int required){
	int count = 1;

	int prev = pos[0];
	for(int i = 0; i < n; i++){
		if(pos[i] - prev  >= distance){
			count++;
			prev = pos[i];
		}
		if(count == required) return true;
	}

	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	if(positions.size() < c) return -1;

	sort(positions.begin(), positions.end());
	// int maxi = INT_MIN;
	// for(auto x: positions) maxi = max(maxi, x);
	int start = 0;
	int end = positions[n-1] - positions[0];
	// int end = maxi;
	int ans = -1;
	while(start<=end){
		int mid  = (start+end)/1;


		if(isPossible(positions, n, mid, c)){
			start = mid+1;
			ans = mid;
		} else {
			end = mid-1;
		}
	}
	return ans;
}