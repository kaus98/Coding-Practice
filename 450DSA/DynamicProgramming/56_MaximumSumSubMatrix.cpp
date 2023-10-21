#include<bits/stdc++.h>

bool kadanesAlgo(vector<int> &dp, int &maxSum, int &top, int &bottom){
    
    int max_sum = INT_MIN;
    int sum_till = 0;
    int s = 0;
    int start = 0;
    int end = 0;
    for(int i = 0; i < dp.size(); i++){
        sum_till = sum_till+dp[i];
        if(sum_till > max_sum){
            max_sum = sum_till;
            end = i;
            start = s;

        }
        if(sum_till < 0){
            sum_till = 0;
            start = i+1;
        }
    }

    if(max_sum > maxSum){
        maxSum = max_sum;
        top = start;
        bottom = end;
        return true;
    }

    return false;
}

void sumArray(vector<vector<int>> &arr, vector<int> &dp, int i){
    for(int j = 0; j < arr.size(); j++){
        dp[j] = dp[j]+arr[j][i];
    }
    return;
}

int maxSumRectangle(vector<vector<int>> arr)
{
    // Write your code here

    int left = 0;
    int right = 0;
    int top = 0;
    int bottom = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < arr[0].size(); i++){
        vector<int> dp(arr.size(), 0);

        for(int j = i; j < arr[0].size(); j++){
            sumArray(arr, dp, j);
            if(kadanesAlgo(dp, maxSum, top, bottom)){
                left= i;
                right = j;
            }
        }
    }
    cout<<"TOP : "<<top<<endl;
    cout<<"BOTTOM : "<<bottom<<endl;
    cout<<"LEFT : "<<left<<endl;
    cout<<"RIGHT : "<<right<<endl;
    return max(0, maxSum); 
}