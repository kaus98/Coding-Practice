#include <bits/stdc++.h>

long long MOD = 1000000007;
long long boardCutting(vector<int>& horizontal, vector<int>& vertical, int m, int n)
{
    // Write Your code here
    priority_queue<pair<long long, int>> pq;
    long long hp = 1, vp = 1;
    long long sum = 0;
    pair<long long, int> temp;

    for(long long i = 0; i < horizontal.size(); i++) pq.push({horizontal[i], 0});
    for(long long i = 0; i < vertical.size(); i++) pq.push({vertical[i], 1});

    while(!pq.empty()){
        temp = pq.top(); pq.pop();

        if(temp.second == 0){
            sum = (sum + temp.first*hp)%MOD;
            vp++;
        } else{
            sum= (sum + temp.first*vp)%MOD;
            hp++;
        }
    }
    return sum;
}
