class Solution {
public:
    // Using the recursion to sort and array
    // One function will be for Sorting and other for Insertion

    void sorting(vector<int>& nums){
        if (nums.size() == 1) return;
        
        int temp = nums[nums.size() - 1];
        nums.pop_back();
        sorting(nums);
        insertion(nums, temp);
    }

    void insertion(vector<int>& nums, int temp){

        if (nums.size() == 0) {nums.push_back(temp); return;}
        if (nums[nums.size()-1] <= temp) {nums.push_back(temp); return;}

        
        int x = nums[nums.size()-1];
        nums.pop_back();
        insertion(nums, temp);
        nums.push_back(x);

    }

    vector<int> sortArray(vector<int>& nums) {
        sorting(nums);
        return nums;
        
    }
};
