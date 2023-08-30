#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // Write your code here.
    int swap = 0;
    int numsneg = 0;
    int j = 0;
    while(j<nums.size() && nums[j] < 0){
        j++;
    }
    for(int i = j+1; i<nums.size(); i++){
        if(nums[i] < 0){
            swap = nums[i];
            nums[i] = nums[j];
            nums[j] = swap;
            j++;
        }
    }
    return nums;
}
