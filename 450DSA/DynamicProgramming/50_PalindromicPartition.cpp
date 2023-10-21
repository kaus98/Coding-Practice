#include <bits/stdc++.h> 

void display2d(vector<vector<int>> &vect){
	for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
    }
}

bool isPalindrome(string str, int i, int j){
    if(i > j) return false;
    if(i == j) return true;

    while(i<j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int f(string s, int i, int j, vector<vector<int>> &dp){
    // if(i > j) return 0;

    //DP equation here
    if(dp[i][j] != -1) return dp[i][j];

    if(isPalindrome(s, i, j)) return dp[i][j] =  0;

    

    int sc = INT_MAX-1;
    int left, right;
    for(int k = i; k < j; k++){
        // int left = f(s, i, k, dp);
        if(dp[i][k] != -1) left = dp[i][k];
        else left = dp[i][k] = f(s, i, k, dp);

        if(dp[k+1][j] != -1) right = dp[k+1][j];
        else right = dp[k+1][j] =  f(s,k+1, j, dp);
        // int right = f(s,k+1, j, dp);
        sc = min(left+right+1, sc);
    }
    return dp[i][j] = sc;
}

int minimumCuts(string str) {
	// Write your code here.	
	// return f(str);
    vector<vector<int>> dp(str.length()+1, vector<int>(str.length()+1, -1));
    return f(str, 0, str.length()-1, dp);
    
}

