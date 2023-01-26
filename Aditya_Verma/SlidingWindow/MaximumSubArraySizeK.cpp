#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int MaximumSubArraySum(vector<int> arr, int k){
    int sum = 0;
    int maxSum = 0;
    
    int i = 0;
    while(i < k){
        sum += arr[i];
        i++;
    }

    maxSum = sum;

    while(i < arr.size()){
        sum += arr[i];
        sum -= arr[i-k];
        i++;
        maxSum = max(sum, maxSum);
    }

    return maxSum;
}

int main(){
    vector<int> arr{2,1,5,6,2,3,1,2,5,2,1,2,5,8,2,4,9,1,2,3,1,2,3,5,6};
    int k = 4;

    int result = MaximumSubArraySum(arr, k);

    cout<<"Maximum Subarray is : "<< result;
}
