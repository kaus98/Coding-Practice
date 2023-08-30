class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(auto x: nums){
            cout<<x<<"\t";
        }
        cout<<endl;

        int interval = -1;
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                interval = i-1;
                //return;
                break;
            }
        }
        if(interval == -1) {reverse(nums.begin(), nums.end()); return;}
        
        for(int i = nums.size()-1; i > interval; i--){
            if(nums[i] > nums[interval]){
                swap(nums[interval], nums[i]);
                break;

            }
        }
        for(auto x: nums){
            cout<<x<<"\t";
        }
        cout<<endl;

        reverse2(nums, interval+1, nums.size()-1);
    };

    void reverse2( vector<int> &arr, int start, int end){
        while(start<end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    };
};