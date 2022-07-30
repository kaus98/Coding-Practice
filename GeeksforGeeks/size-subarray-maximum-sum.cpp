#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int size_subarra_maximum_sum(int * arr, int N){
    int start = 0, end = 0, s = 0, max = 0, max_so_far = INT_MIN;

    for (int i = 0; i < N; i++){
        max += arr[i];
        if (max_so_far <= max){
            max_so_far = max;
            start = s;
            end = i;
        }
        if (max < 0){
            max_so_far = 0;
            s = i+1;
        }
    }

    return (end-start+1);
}

int main(){
    // Geeks For Geeks Problem : https://www.geeksforgeeks.org/size-subarray-maximum-sum/

    int N = 5;
    int arr[] = {1,-1,3,-2,2};

    int result = size_subarra_maximum_sum(arr, N);
    cout<< "Size of Subarray with Max Sum : " << result << " \n";

}