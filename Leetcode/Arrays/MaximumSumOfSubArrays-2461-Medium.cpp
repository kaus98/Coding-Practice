class Solution {
public:
    
    long long maximumSubarraySum(vector<int>& nums, int k) {
        return maximumSubarraySumArray(nums, k);
    }

    //Array perform better with SubArrays
    long long maximumSubarraySumArray(vector<int>& nums, int k) {
        long long sum = 0;
        long long maximum = 0;
        int count[100011] = {};
        long long counter = 0;

        int i = 0;
        while( i < k ){
            sum += nums[i];

            count[nums[i]] += 1;
            if (count[nums[i]] > 1){
                counter++;
            }
            
            i++;
        }
        if (counter == 0){
            maximum = sum;
        }
        

        while(i < nums.size()){

            sum += nums[i];
            sum -= nums[i-k];

            count[nums[i-k]] -= 1;
            if(count[nums[i-k]] != 0) counter--;

            count[nums[i]] += 1;
            if (count[nums[i]] > 1){
                counter++;
            }
        

            i++;

            if (sum > maximum && counter == 0){
                maximum = sum;
            }
        }

        return maximum;
    }
    // Dictionary Perform much poor then Array
    long long maximumSubarraySumDict(vector<int>& nums, int k) {
        long long sum = 0;
        long long maximum = 0;
        map<int, int> count;
        long long counter = 0;

        int i = 0;
        while( i < k ){
            sum += nums[i];

            // Check if key exists
            if(count.find(nums[i]) == count.end()){
                // Not Found
                count[nums[i]] = 1;
            } else {
                // Found
                count[nums[i]] += 1;
                if (count[nums[i]] > 1){
                    counter++;
                }
            }
            i++;
        }
        if (counter == 0){
            maximum = sum;
        }
        

        while(i < nums.size()){

            sum += nums[i];
            sum -= nums[i-k];

            count[nums[i-k]] -= 1;
            if(count[nums[i-k]] != 0) counter--;

            if(count.find(nums[i]) == count.end()){
                // Not Found
                count[nums[i]] = 1;

            } else {
                // Found
                count[nums[i]] += 1;
                if (count[nums[i]] > 1){
                    counter++;
                }
            }

            i++;

            if (sum > maximum && counter == 0){
                maximum = sum;
            }
        }

        return maximum;
    }
};

// 2461. Maximum Sum of Distinct Subarrays With Length K

// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

//     The length of the subarray is k, and
//     All the elements of the subarray are distinct.

// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.

 

// Constraints:

//     1 <= k <= nums.length <= 105
//     1 <= nums[i] <= 105

