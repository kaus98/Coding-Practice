#include<bits/stdc++.h>

int f(vector<pair<int,int>> &p, int n, int prev, int i){

    if(i==n) return 0;

    //check condition if it can be added
    int inc = 0;
    if(prev < p[i].first){
        inc = 1 + f(p, n, p[i].second, 0);
    }
    int exc = f(p, n, prev, i+1);

    return max(inc, exc);
}

//Memorization Doesnt work as this is solved by Greedy Algo in this question.
//Only able to solve 6/10 test cases.
int fm(vector<pair<int,int>> &p, int n, int prev, int i, map<pair<int,int>, int> &mp){

    if(i==n) return 0;

    //check if Exists
    if(mp.find({prev,i}) != mp.end()){
        return mp[{prev,i}];
    }
    //check condition if it can be added
    int inc = 0;
    if(prev < p[i].first){
        inc = 1 + fm(p, n, p[i].second, 0, mp);
    }
    int exc = fm(p, n, prev, i+1, mp);

    return mp[{prev,i}] = max(inc, exc);
}

bool sol(pair<int, int> &a, pair<int, int> &b){
    return a.second<b.second;
}
int greed(vector<pair<int, int>> &p, int n){

    sort(p.begin(), p.end(), sol);

    int sum = 1;
    int prev = p[0].second;
    for(int i = 1; i < n; i++){
        if(p[i].first > prev){
            sum++;
            prev = p[i].second;
        }
    }

    return sum;

}
int maxLengthChain(vector<pair<int, int>> &p, int n) {
    // Write your code here.
    //Recursion Solution
    // return fm(p, n, INT_MIN+1, 0);

    //Recursion + Memorisation Solution
    // map<pair<int,int>, int> mp;
    // return fm(p, n, INT_MIN+1, 0, mp);

    return greed(p, n);
}

