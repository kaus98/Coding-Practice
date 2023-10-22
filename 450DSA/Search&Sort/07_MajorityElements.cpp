#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int freq = 1;
	int num = INT_MAX;

	for(int i = 0; i < n; i++){
		int x = arr[i];
		if(x != num){
			freq--;
			if(freq == 0) {num = x; freq++;}
		} else {
			freq++;
		}
	}

	//Double check if it is truly Majority Element
	// cout<<"Num :: "<<num<<endl;
	freq = 0;
	for(int i = 0; i < n; i++){
		int x = arr[i];
		if(num == x)freq++;
	}
	if(freq > (n/2)) return num;
	return -1;
}