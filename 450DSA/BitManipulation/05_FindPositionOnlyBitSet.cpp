#include <bits/stdc++.h> 
int findSetBit(int N) {   
    // Write your code here
    if(__builtin_popcount(N)!=1) return -1;
    int result = 1;

    while(N>>result) result++;
    return result;
}

