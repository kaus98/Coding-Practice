#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */

    int sum = 0;
    int max_sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        max_sum = max(max_sum, sum);

        sum = max(sum, 0);
    }
    //    //return max(max_sum,0);
    return max_sum;
}