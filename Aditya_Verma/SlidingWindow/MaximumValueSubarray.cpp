#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

deque<int> PushBack(deque<int> g, int k){
    while(!g.empty() && g.back() < k) g.pop_back();
    g.push_back(k);
    return g;
}

deque<int> PullBack(deque<int> g){
    int i = g.front();
    g.pop_front();
    cout << "Pull Back Called : "<<i << endl;
    while(!g.empty() && i < g.front() && g.size() > 1){
        i = g.front();
        g.pop_front();
    }
    return g;
}

vector<int> MaxValueSizeK(vector<int> arr, int k){
    deque<int> g;

    int i = 0;
    int j = 0;
    vector<int> result;
    cout<<"From the Function" << endl;
    
    while(j < k){
        // cout<<"Working from Value J : "<<j<<endl;
        g = PushBack(g, arr[j]);
        j++;
    }
    // cout << "Pushing to Arr : "<< g.front()<<endl;
    result.push_back(g.front());
    // cout << "Size of Result : "<<result.size() << endl;

    while(j < arr.size()){
        g = PushBack(g, arr[j]);
        j++;
        // cout<<"Pushed the value in Queue "<< endl;
        if(arr[i++] == g.front()) g.pop_front();
        // i++;

        
        // cout << "Size of Result : "<<result.size() << endl;
        result.push_back(g.front());
    }

    return result;
}

int main(){
    vector<int> arr{2,-1, -2, -3, -1,5,1,2,3,-1,2,5,2,1,-2,5,8,2,4,-9,1,2,3,1,-2,3,5,6};
    int k = 4;
    cout<<"Starting the Function";
    vector<int> result = MaxValueSizeK(arr, k);

    cout<<endl;
    for(auto x: result) cout<< x << "\t";
    cout<<endl;

    return 0;
}
