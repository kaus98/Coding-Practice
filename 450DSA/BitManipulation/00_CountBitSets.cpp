#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

    //Write your countBits function here

int countBits(int n){
    int result = 0;

    while(n){ result++; n = n&(n-1);}
    return result;
}
int main() {
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}