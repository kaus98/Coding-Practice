class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> ll;
        vector<int> output;

        int start = 0;

        // Building the Initial List
        for(int i = 0; i < k; i++){
            while(!ll.empty() && ll.back()<nums[i]) ll.pop_back();
            ll.push_back(nums[i]);
        }

        output.push_back(ll.front());
        //Sliding the Windows to find the max;

        for(int i = k; i < nums.size(); i++){
            // Calculations to remove the front of array 
            if(ll.front() == nums[start]) ll.pop_front();
            
            // Calculations to add the new value in list
            while(!ll.empty() && ll.back() < nums[i]) ll.pop_back();
            ll.push_back(nums[i]);
            // Calculations to add the value to array and increase the value of start
            output.push_back(ll.front());
            start++;
        }

        return output;
    }
};
