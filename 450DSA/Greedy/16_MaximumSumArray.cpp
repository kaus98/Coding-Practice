#include <bits/stdc++.h> 
int MOD = 1000000007;

long long maximumSum(vector<int> &a, int n) {
    // Write your code here.
    sort(a.begin(), a.end());
    long long pro = 0;
    for(int i = 0; i < n; i++){
        pro = (pro + (i*a[i])%MOD)%MOD;
    }
    return pro;
}