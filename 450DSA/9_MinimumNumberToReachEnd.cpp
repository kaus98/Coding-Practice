class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int max_jump = 1;
        int MAXI = nums[0];
        int temp = nums[0];
        int target = nums.size() - 1;
        for(int i = 1; i<target ; i++){
            if(nums[i]+i > MAXI){
                MAXI = nums[i]+i;
            }
            if(temp == i) {max_jump++;temp = MAXI;}
            // cout<<"Steps : "<<steps << " Max_Jump : "<< max_jump << " MAXI : "<< MAXI <<endl;
        }
        return max_jump;
    }
}