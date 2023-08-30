// V. Important Question
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Start to work on 2 approach 
        // First one i will make changes in array and in second approach i cant make any chance in array.
        // Second will use Floyd Cycle detection method in Linked List

        // Second method
        int first_pointer = nums[0];
        int second_pointer = nums[0];

        while(true){
            first_pointer = nums[first_pointer];
            second_pointer = nums[nums[second_pointer]];
            if (first_pointer == second_pointer) break;
        }
        second_pointer = nums[0];

        while(first_pointer != second_pointer){
            first_pointer = nums[first_pointer];
            second_pointer = nums[second_pointer];
            //if(first_pointer == second_pointer) break;
        }


        return first_pointer;

        // First method
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i])] < 0) return abs(nums[i]);
            else nums[abs(nums[i])] *= -1;
        }
        return 0;
    }
};