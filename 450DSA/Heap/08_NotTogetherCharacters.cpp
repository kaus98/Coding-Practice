#include <bits/stdc++.h> 
vector<int> rearrange(vector<int>& num)
{
    //  Write you code here
    //  Return a valid rearrangement
    //  Return {-2147483648}, if there is no valid rearrangement

    // pair<count, character> will use to push in priority queue

    map<int, int> mp;
    for(int i = 0; i < num.size(); i++){
        mp[num[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for(auto x: mp){
        pq.push({x.second, x.first});
    }

    int i = 0;
    pair<int, int> temp = pq.top();
    if(temp.first > (num.size()+1)/2) return {-2147483648};
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        while(temp.first > 0){
            num[i] = temp.second;
            i+=2;
            if(i >= num.size()) i = 1;
            temp.first--;
        }
        
        // if(temp.first != 1){
        //     pq.push({temp.first-1, temp.second});
        // }
        
        
        

    }
    // cout<<endl;
    // for(auto x: num) cout<<x<<"\t";
    // cout<<endl;
    return num;
}