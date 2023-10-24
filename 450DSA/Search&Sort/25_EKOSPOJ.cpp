// Solved Similar Question 
// https://www.codingninjas.com/studio/problems/kevin-and-his-fruits_1164267

#include <bits/stdc++.h> 

bool isPossible(vector<int> &arr, int minF, int mid){

    long long int sum = 0;

    for(int i = 0; i < arr.size(); i++){
        sum += max(0, arr[i]-mid);
        if(sum >= minF) return true;
    }

    return false;
}

int getMaxMarker(vector<int> &arr, int totalB, int minF)
{
    //  Write your code here.a

    long long int start = 0, end= 0, mid, ans = -1; 

    for(auto x: arr) {
        end += x;
    }

    while(start <= end){
        mid = start + (end-start)/2;

        // cout<<"Start :: "<<start<<" :: "<<" End :: "<<end<<" :: "<<mid<<endl;

        if(isPossible(arr, minF, mid)){
            ans = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
    }

    return ans;
}