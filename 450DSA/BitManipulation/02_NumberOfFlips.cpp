#include <bits/stdc++.h> 
int numberOfFlips(int a, int b)
{
    // Write your code here.
    // return __builtin_popcount(a^b);

    int n = a^b;
    int c = 0;
    
    while(n){ c++; n&=(n-1);}

    return c;
}