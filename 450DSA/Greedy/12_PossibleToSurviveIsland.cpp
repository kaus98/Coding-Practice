#include <bits/stdc++.h> 
bool isPossibleToSurvive(int n, int x, int d){
    // Write your code here
    if(n<x) return false;

    long long x1 = x*d;
    long long x2 = n*6;

    if(x1 > x2) return false;
    return true;
    
}
