#include <bits/stdc++.h> 
int findMinDiff(int n, int m, vector<int> chocolates) {
    // Write your code here.
    sort(chocolates.begin(), chocolates.end());


    int sum = INT_MAX;
    int diff = 0;
    int i = 0;
    int j = m-1;

    while(j < n){

        diff = chocolates[j++] - chocolates[i++];
        sum = min(sum, diff);
    }

    return sum;


}