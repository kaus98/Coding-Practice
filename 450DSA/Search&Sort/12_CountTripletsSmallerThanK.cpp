#include <bits/stdc++.h> 
int threeSumSmaller(int n, vector<int> arr, int target) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    int count = 0;

    for(int i = 0; i < n-2; i++){
        int start = i + 1;
        int end = n-1;

        while(start < end){
            if(arr[i] + arr[start] + arr[end] < target){
                count+= end-start;
                start++;
            } else end--
        }
    }
    return count;
}
