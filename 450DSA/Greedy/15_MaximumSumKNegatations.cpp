#include <bits/stdc++.h> 
int getSum(vector<int> &arr){
    int sum = 0;
    for(auto x: arr) sum+=x;
    return sum;
}

int maxSumAfterKflips(vector<int> &arr, int k, int n){
    // Write your code here
    sort(arr.begin(), arr.end());

    int i = 0;

    while(arr[i] < 0 && k>0){
        arr[i]*=-1;
        i++;
        k--;
    }
    if(k==0) return getSum(arr);

    sort(arr.begin(), arr.end());
    if(arr[0]== 0 || k%2==0) return getSum(arr);

    arr[0]*=-1;

    return getSum(arr);
}

