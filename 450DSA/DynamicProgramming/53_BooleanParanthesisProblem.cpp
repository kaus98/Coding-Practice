#include<bits/stdc++.h>

int MAX = 1000000007;

bool check(char c){
    if(c=='T') return true;
    else return false;
}

long long getWays(char c, long long leftT, long long leftF, long long rightT, long long rightF, bool isTrue){
    
    if(c == '|'){
        // cout<<"Getting the ways for | :: "<<c<<endl;
        if(isTrue) return ((leftT*rightT)%MAX + (leftT*rightF)%MAX + (leftF*rightT)%MAX)%MAX;
        else return (leftF*rightF)%MAX;
    } else if(c=='&'){
        // cout<<"Getting the ways for & :: "<<c<<endl;
        if(isTrue) return (leftT*rightT)%MAX;
        else return ((leftF*rightF)%MAX + (leftT*rightF)%MAX + (leftF*rightT)%MAX)%MAX;
    } else {
        // cout<<"Getting the ways for ^ :: "<<c<<endl;
        if(isTrue) return ((leftT*rightF)%MAX + (leftF*rightT)%MAX)%MAX;
        else return ((leftF*rightF)%MAX + (leftT*rightT)%MAX)%MAX;
    }

    return 0;
}
int f(string exp, int i, int j, bool isTrue, map<pair<pair<int,int>, bool>, long long> &mp){
    // It should return the number of ways

    // Break condition
    if(i==j){
        // cout<<"Equal found at :: "<<i<<" :: "<<exp[i]<<endl;
        if( (isTrue && check(exp[i])) || (!isTrue && !check(exp[i])) ) return 1;
        else return 0;
    }

    if(mp.find({{i,j},isTrue}) != mp.end()) return mp[{{i,j},isTrue}];
    if(i>j) return 0;
    long long ways = 0;
    long long leftT, leftF, rightT, rightF;
    for(int k = i+1; k < j; k+=2){
        leftT = f(exp, i, k-1, true, mp);
        leftF = f(exp, i, k-1, false, mp);
        rightT = f(exp, k+1, j, true, mp);
        rightF = f(exp, k+1, j, false, mp);

        ways += getWays(exp[k] , leftT, leftF, rightT, rightF, isTrue)%MAX;

    }

    return mp[{{i,j},isTrue}] = ways%MAX;
}

int evaluateExp(string & exp) {
    // Write your code here.
    map<pair<pair<int,int>, bool>, long long> mp;
    return f(exp, 0, exp.length()-1, true, mp);
}

