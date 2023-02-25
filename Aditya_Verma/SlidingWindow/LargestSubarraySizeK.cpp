#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int MaxValueSubarrayK(vector<int> arr, int k){
    int mx = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    while(j < arr.size()){
        if(sum == k){
            mx = max(mx, j-i);
            sum+= arr[j];
            j++;
        }

        else if(sum > k){
            sum -= arr[i];
            i++;
        }

        else if(sum < k){
            sum+= arr[j];
            j++;
        }
        else{
            break;
        }
    }
    return mx;
}

int main(){
    vector<int> arr{4,1,2,1,3,3};
    int k = 4;
    cout<<"Starting the Function";
    int result = MaxValueSubarrayK(arr, k);

    cout<< result << "\t";
    return 0;
}
