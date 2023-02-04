//https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

void showpqmin(priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout<<endl;
}

void showpqmax(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout<<endl;
}


void medianStream2(vector<int> arr){
    priority_queue <int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    float ans;
    for(auto x: arr){
        if(minHeap.empty() || maxHeap.top() < x){
            minHeap.push(x);
            while(!minHeap.empty()  && (minHeap.size() > maxHeap.size())){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } 
        else {
            maxHeap.push(x);
            while(!maxHeap.empty()  && (maxHeap.size() > minHeap.size())){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        } 

        cout<<"Min Heap is : ";
        showpqmin(minHeap);
        cout<<"Max Heap is : ";
        showpqmax(maxHeap);

        if(minHeap.size() == maxHeap.size()) ans = (float)((minHeap.empty()?0:minHeap.top()) + (maxHeap.empty()?0:maxHeap.top()))/2 ;
        else ans = (float)((minHeap.size() > maxHeap.size())?minHeap.top():maxHeap.top());
        cout<< "Median of Array is : "<< ans << endl;
    }
}

int main(){
    
    vector<int> arr = {1,206,76,544,21,6,81,6,8,10,2512,15,136,864,12,23,48,1992,162};
    medianStream2(arr);
    return 0;
}