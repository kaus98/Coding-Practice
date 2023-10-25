#include <bits/stdc++.h> 

int solve(vector<int> &ham, int sum, int a, int b, int index){

    if(index == ham.size()) 
        if(sum >= a && sum <= b) return 1;
        else return 0;

    int count = 0;
    //Inclusion
    count += solve(ham, sum+ham[index], a, b, index+1);

    //Exclusion
    count += solve(ham, sum, a, b, index+1);

    return count;
}

int solveDp(vector<int> &ham, int sum, int a, int b, int index, map<pair<int, int>, int> &dp){
    if(index == ham.size()) 
        if(sum >= a && sum <= b) return 1;
        else return 0;

    if(dp.find({index, sum}) != dp.end()) 
        return dp[{index, sum}];

    int count = 0;
    
    //Inclusion
    count += solveDp(ham, sum+ham[index], a, b, index+1, dp);

    //Exclusion
    count += solveDp(ham, sum, a, b, index+1, dp);

    return dp[{index, sum}] = count;
}
int makeHappyGroup(vector<int> &happiness, int n, int a, int b) {
  // Write your code here.

    map<pair<int, int>, int> mp;
    return solveDp(happiness, 0, a, b, 0, mp);
}