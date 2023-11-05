#include <bits/stdc++.h> 

vector<int> MergeSortedPriorityQueue(vector<vector<int>> &arr, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < arr.size(); i++){
        pq.push(make_pair(arr[i][0], i));
        // cout<<"Pushing the Element :: "<<arr[i][0]<<endl;
    }

    vector<int> result;
    pair<int, int> top;
    int row;
    vector<int> temp(arr.size() , 0);
    while(!pq.empty()){
        top = pq.top();
        result.push_back(top.first);
        row = top.second;
        pq.pop();
        if(temp[row]+1 < arr[row].size()) {pq.push(make_pair(arr[row][temp[row]+1], row)); temp[row]+=1;}


    }
    return result;
}



vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    // Write your code here. 
    //First Implementatin will use priority queue to find the min in first elements and then merge
    //Second method will use Heapify Method to filter

    //Using Priority Queue

    vector<int> result = MergeSortedPriorityQueue(arr, k);
    return result;

}
