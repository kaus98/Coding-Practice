int countSetBits(int n) {
    // Write your code here
    if(n==0) return 0;
    int N = 0;
    while(1<<N <= n) N++;
    N--;

    //Sum before 1<<N & Sum of First Character of number after 1<<N

    return N*(1<<(N-1)) + n-(1<<N)+1 + countSetBits(n-(1<<N));

}