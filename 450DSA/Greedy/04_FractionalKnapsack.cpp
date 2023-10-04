#include <bits/stdc++.h>

bool comp(pair<int, int> &a, pair<int, int> &b){
    double x = (double)a.second/(double)a.first;
    double y = (double)b.second/(double)b.first;

    return x > y;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), comp);
    double profit = 0;

    for(auto x: items){
        int weight = x.first;
        int value = x.second;

        if(w >= weight){
            w-=weight;
            profit+=value;
        } else {
            profit += ((double)value*(double)w)/(double)weight;
            w = 0;
        }
    }

    return profit;
}