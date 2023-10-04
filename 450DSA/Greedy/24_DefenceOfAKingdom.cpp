#include<bits/stdc++.h>
#include <iostream>

using namespace std;

bool comp1(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}

bool comp2(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}


int solve(vector<pair<int, int>> &pawns, int n, int m){
    int x1 = INT_MIN, x2 = INT_MIN;
    sort(pawns.begin(), pawns.end(), comp1);

    for(int i = 1; i < pawns.size(); i++){
        x1 = max(x1, pawns[i].first-pawns[i-1].first);
    }

    sort(pawns.begin(), pawns.end(), comp2);

    for(int i = 1; i < pawns.size(); i++){
        x2 = max(x2, pawns[i].second-pawns[i-1].second);
    }

    return (x1-1)*(x2-1);

}
int main(){
    int n;

    cin>>n;

    while(n--){
        int a,b,c;

        cin>>a>>b>>c;

        vector<pair<int, int>>  pawns;
        int t1,t2;
        for(int i = 0; i < c; i++){
            cin>>t1>>t2;
            pawns.push_back({t1, t2});
        }
        pawns.push_back({0,0});
        pawns.push_back({a+1,b+1});

        cout<<solve(pawns, a, b)<<endl;

    }
}
