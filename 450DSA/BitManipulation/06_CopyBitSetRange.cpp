#include <bits/stdc++.h> 
int copyBitsInRange(int a, int b, int x, int y)
{
    // Write your code here.
    for(int i = x-1; i <= y-1; i++){ b = b|(a&(1<<i)); }
    return b;
}