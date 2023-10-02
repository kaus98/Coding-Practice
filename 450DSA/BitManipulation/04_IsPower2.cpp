bool isPowerOfTwo(int n)
{	
    // Write your code here.
    return __builtin_popcount(n)==1;
}