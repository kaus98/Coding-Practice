// https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int ConnectRopes(vector<int> &arr)
{
    // Program to minimise the cost of adding the amount with minimum cost
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto x : arr)
    {
        minHeap.push(x);
    }
    int i, j;
    while (minHeap.size() != 1)
    {
        i = minHeap.top();
        minHeap.pop();
        j = minHeap.top();
        minHeap.pop();
        minHeap.push(i + j);
    }
    return minHeap.top();
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int k = ConnectRopes(arr);
    cout << "Minimum Cost is : " << k;
}