#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

struct int2{
    int i = 0;
    int j = 0;
};

int2 search2D(vector<vector<int>> &arr, int search){

    int2 res;
    res.j = arr[0].size()-1;

    while(res.i < arr.size()-1 && res.j > -1){
        if(arr[res.i][res.j] == search) return res;
        // If value if bigger than search, we can safely ignore that complete column
        if(arr[res.i][res.j] > search) res.j--;
        // Value can be found in that Column so we can move down
        if(arr[res.i][res.j] < search) res.i++;
    }

    res.i = -1;
    res.j = -1;
    return res;
}

int main(){
    vector<vector<int>> mat = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    
    int2 res = search2D(mat, 34);

    cout << "Value Found at i : "<<res.i<<" j : "<< res.j;
}