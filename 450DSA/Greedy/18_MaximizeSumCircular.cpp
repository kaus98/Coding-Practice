#include <bits/stdc++.h> 
int maxSum(vector<int> &arr, int n)
{
	// Write your code here.
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = n-1;
    int sum = 0;
    bool temp = true;

    while(i < j){
        sum+= abs(arr[i] - arr[j]);
        if(temp) i++;
        else j--;
        temp = !temp;
    }

    sum+= abs(arr[n/2]-arr[0]);

    return sum;
}