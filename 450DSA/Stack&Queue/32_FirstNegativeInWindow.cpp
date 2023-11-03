#include <bits/stdc++.h> 
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{

    //Write your code here

    queue<int> qu;
    vector<int> res;

    int i = 0;
    int j = 0;
    //Filling the queue
    while(j < k){
        if(arr[j] < 0) qu.push(arr[j]);
        j++;
    }
    if(!qu.empty()) res.push_back(qu.front());
    else res.push_back(0);

    while(j<n){
        if(arr[i] == qu.front()) qu.pop();

        if(arr[j] < 0) qu.push(arr[j]);
        if(!qu.empty()) res.push_back(qu.front());
        else res.push_back(0);
        j++;
        i++;
    }

    return res;

}

