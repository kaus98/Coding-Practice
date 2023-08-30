class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        
        int prof = 0;

        for(auto x: prices){
            mini = min(x, mini);
            prof = max(x-mini, prof);
        }

        return prof;
    }
};