#include<bits/stdc++.h>

// Function to calculate minimum cost.
long long minimumCost(vector<int> &cost, int n, int k)
{
    // Write your code here.
    sort(cost.begin(), cost.end());

    int i = 0;
    int j = n-1;
    long long ct = 0;

    while(i<=j){
        ct+=cost[i];
        i++;
        j-=k;
    }

    return ct;
}

// Function to calculate maximum cost.
long long maximumCost(vector<int> &cost, int n, int k)
{
    // Write your code here.
    sort(cost.begin(), cost.end(), greater<int>());

    int i = 0;
    int j = n-1;
    long long ct = 0;

    while (i <= j) {
        ct += cost[i];
        i++;
        j -= k;
    }

    return ct;
}