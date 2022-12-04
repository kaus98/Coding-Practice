class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long arr[amount+1];
        for (int i=0; i <= amount; i++){
            arr[i] = INT_MAX-1;   
        }
        arr[0] = 0;

        for(int i = 1; i<amount+1; i++){
            for(auto x: coins){
                if((i-x)>-1 && arr[i-x] != (INT_MAX-1)){
                    arr[i] = min(arr[i], arr[i-x]+1);
                }
            }
        }
        
        if(arr[amount]==INT_MAX-1) return -1;
        return arr[amount];
    }
};
