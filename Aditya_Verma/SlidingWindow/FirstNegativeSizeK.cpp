#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

vector<int> FirstNegativeSubArrayK(vector<int> arr, int k){
    stack<int> st;

    int i = 0;
    vector<int> ans;

    while(i < k){
        if(arr[i] < 0) st.push(arr[i]);
        i++;
    }

    while(i < arr.size()){
        if(arr[i] < 0) st.push(arr[i]);
        if(!st.empty() && arr[i-k] == st.top()) st.pop();

        if(st.empty()) ans.push_back(0);
        else ans.push_back(st.top());

        i++;
    }

    return ans;

}


int main(){
    vector<int> arr{2,-1,5,6,2,3,-1,2,5,2,1,-2,5,8,2,4,-9,1,2,3,1,-2,3,5,6};
    int k = 4;
    vector<int> result = FirstNegativeSubArrayK(arr, k);

    cout<<endl;
    for(auto x: result) cout<< x << "\t";
    cout<<endl;
}
