#include <bits/stdc++.h> 
int findPos(int N, int K, int H, vector<int>& A)
{
    // Write your code here.
    // N -> Size of Array
    // K -> Maximum Difference in Adjacent Heights
    // H -> Height to search
    
    int i=0;
    
    while(i < N){

        // cout<<"Looking the value in :: "<<i<<endl;
        if(A[i] == H) return i;

        int dif = abs(A[i]-H)/K;
        i += max(1,dif);
    }
    return -1;
}