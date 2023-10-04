#include <bits/stdc++.h> 
int MOD = 1000000007;
long long int maxProductSubset(vector<int> &arr, int n)
{
    // Write your code here.
    
    if(n==1) return arr[0];
    
    sort(arr.begin(), arr.end());

    long long int sum = 0;
    int i = 0;

    bool zeroset = false;
    while(i < n){


        if(arr[i] < 0){
            if(sum < 0) sum= (sum*arr[i])%MOD;
            else {
              if (i != (n - 1) && arr[i+1] < 0){
                  if(sum==0) sum = 1;
                  sum= (sum*arr[i])%MOD;
              } 
            }
        }
        if(arr[i] == 0){
            zeroset = true;
        }
        if(arr[i] > 0){
            if(sum == 0) sum = 1;
            sum= (sum*arr[i])%MOD;
        }
        i++;
    }
    if(sum < 0 && zeroset) return 0;
    return sum;

}