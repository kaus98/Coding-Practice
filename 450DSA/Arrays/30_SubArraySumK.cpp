class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0 ;
        int j = 0;
        int result = INT_MAX;
        int sum = 0;
        while(j < nums.size() || sum >= target){
            if(sum < target){
                sum+=nums[j++];
            } else{
                result = min(result, j-i);
                sum-=nums[i++];
            }
        }

        return result==INT_MAX?0:result;
    }
};