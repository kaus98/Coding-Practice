#include<bits/stdc++.h>
bool st(vector<int> &a, vector<int> &b){

    // if(a[1] == b[1]) return (a[2] > b[2]);
    // else return a[1] < b[1];
    return a[2] > b[2];
}

//This is also accepted approach but failing here
vector<int> greedyApproach(vector<vector<int>> &jobs){
    sort(jobs.begin(), jobs.end(), st);

    int deadline = 0;
    for(auto x: jobs) deadline = max(deadline, x[2]);

    vector<bool> visit(deadline, false);
    int njobs = 0;
    int nprofit = 0;

    for(auto x: jobs){
        int dead = x[1];
        int pro = x[2];

        for(int i = dead-1; i >= 0; i--){
            if(visit[i] == false){
                njobs++;
                nprofit+=pro;
                visit[i] = true;
                i = -1;
            }
        }
    }

    vector<int> result;
    result.push_back(njobs);
    result.push_back(nprofit);
    return result;
}

//Accepted Method
//Uses O(MaxDeadline) + O(N)
vector<int> heapApproach(vector<vector<int>> &jobs){
    int deadline = 0;
    map<int, vector<int>> mp;
    for(auto x: jobs){
        mp[x[1]].push_back(x[2]); // Map of deadline to Profit
        deadline = max(deadline, x[1]); // Max deadline occured yet
    }

    priority_queue<int> pq;
    int profit = 0, n = 0;

    for(int i = deadline; i > 0; i--){
        for(auto x: mp[i]) pq.push(x);

        if(!pq.empty()){
            profit+=pq.top();
            n++;
            pq.pop();
        }
    }

    vector<int> result;
    result.push_back(n);
    result.push_back(profit);
    return result;
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    vector<int> result = heapApproach(jobs);
    return result;
}
