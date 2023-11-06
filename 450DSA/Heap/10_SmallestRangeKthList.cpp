#include <bits/stdc++.h>

vector<pair<int,int>> MergeSortedPriorityQueue(vector<vector<int>> &arr){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < arr.size(); i++){
        pq.push(make_pair(arr[i][0], i));
        // cout<<"Pushing the Element :: "<<arr[i][0]<<endl;
    }

    vector<pair<int,int>> result;
    pair<int, int> top;
    int row;
    vector<int> temp(arr.size() , 0);
    while(!pq.empty()){
        top = pq.top();
        result.push_back(top);
        row = top.second;
        pq.pop();
        if(temp[row]+1 < arr[row].size()) {pq.push(make_pair(arr[row][temp[row]+1], row)); temp[row]+=1;}
    }

    return result;
}


int kSorted(vector<vector<int>> &a, int k, int n){
    typedef pair<int, int> tt;

    priority_queue<tt, vector<tt> , greater<tt> > pq;
    vector<int> temp(k,0);

    int dif = 0;
    int MINI = INT_MAX-1;
    int MAXI = INT_MIN+1;


    for(int i = 0; i < k; i++){
        pq.push(make_pair(a[i][0], i));
        MINI = min(MINI, a[i][0]);
        MAXI = max(MAXI, a[i][0]);
    }

    dif = MAXI-MINI+1;
    pair<int, int> t1;

    while(!pq.empty()){
        t1 = pq.top();
        pq.pop();
        if(temp[t1.second]+1 >= a[t1.second].size()){
            break;
        }
        MAXI = max(MAXI, a[t1.second][temp[t1.second]+1]);

        pq.push(make_pair(a[t1.second][temp[t1.second]+1], t1.second));
        MINI = pq.top().first;

        dif = min(dif, MAXI-MINI+1);
        temp[t1.second]++;
    }

    return dif;
}


int kSortedFirstApproch(vector<vector<int>> &a, int k, int n) {
    // This is giving the time out;
    // Write your code here.
    vector<pair<int,int>> result = MergeSortedPriorityQueue(a);

    map<int, int> mp;

    int start = 0;
    int end = 0;
    int minD = INT_MAX - 1;
    int check = 0;

    while(check < k){
        mp[result[end].second]++;

        if(mp[result[end].second] == 1) check++;
        end++;
        
    }
    while(mp[result[start].second] > 1){
        mp[result[start].second]--;
        start++;
    }
    minD = result[end-1].first-result[start].first;
        
    
    // return 0;
    while(end < result.size()){
        mp[result[end].second]++;
        while(mp[result[start].second] > 1){
            mp[result[start].second]--;
            start++;
        }
        minD = min(minD, result[end].first-result[start].first);
        end++;
    }

    return minD+1;

}