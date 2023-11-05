#include <bits/stdc++.h> 
vector<int> Klargest(vector<int> &a, int k, int n) {
    // Write your code here

    //Using Sorting
    sort(a.begin() , a.end());
    vector<int> b; // cretinga  a new vector
    for(int i =n-k; i<n; i++){   // from n-k to n
        b.push_back(a[i]);      // pushing in vector
    }
    return b;


    //Using Priority queue
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> result;
    int i = 0;
    while(i<n){
        pq.push(a[i]);
        if(pq.size() > k) pq.pop();
        i++;
    }

    while(!pq.empty()){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;

}