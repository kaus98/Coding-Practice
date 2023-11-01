#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

bool comp(vector<int> &a, vector<int> &b) {return a[0] < b[0];}
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    // Write your code here
    sort(intervals.begin(), intervals.end(), comp);

    // cout<<"Sorted array :: "<<endl;
    // for(int i = 0; i < intervals.size(); i++) cout<<intervals[i][0] << " :: "<<intervals[i][1]<<endl;
    // cout<<endl;
    
    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++){
        if(res[res.size()-1][1] >= intervals[i][0]){
            res[res.size()-1][1] = max(res[res.size()-1][1],intervals[i][1] );
        }
        else {
            res.push_back(intervals[i]);
        }
    }

    return res;
}
