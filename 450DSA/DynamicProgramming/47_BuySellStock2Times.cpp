class Solution {
public:

    int greedyApproach(vector<int> &prices){
        int i = 0;
        int j = 0;
        int n = prices.size();

        vector<int> left(prices.size(), 0);
        vector<int> right(prices.size(), 0);

        int left_min = INT_MAX-1;
        int right_max = -1;
        int res = 0;
        // Moving left to right

        left_min = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] <= left_min) left_min = prices[i];
            left[i] = max(left[i-1], prices[i] - left_min);

        }
        
        right_max = prices[n-1];
        for(int i = n-2; i>-1; i--){
            if(prices[i] >= right_max) right_max = prices[i];
            right[i] = max(right[i+1], right_max - prices[i]);
        }

        for(int i = 0; i<n; i++) res = max(res, left[i]+right[i]);
        
        return res;
    }

    int solve(vector<int> &prices, int index, int buy, vector<vector<vector<int>>> &dp, int count){
        if(index == prices.size()) return 0;
        if(count < 0) return 0;

        if(dp[index][buy][count] != -1) return dp[index][buy][count];
        if(buy) return dp[index][buy][count] = max(solve(prices, index+1, 0, dp, count) - prices[index] , solve(prices, index+1, 1, dp, count));
        else return dp[index][buy][count] = max(solve(prices, index+1, 1, dp, count-1) + prices[index], solve(prices, index+1, 0, dp, count));
    }

    int solveTab(vector<int> &prices){
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index = prices.size() - 1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int count = 1; count <= 2; count++){
                    if(buy){
                        dp[index][buy][count] = max(dp[index+1][0][count] - prices[index] , dp[index+1][1][count]);
                    } else {
                        dp[index][buy][count] = max(dp[index+1][1][count-1] + prices[index], dp[index+1][0][count]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        // return solve(prices, 0, 1, dp, 1);

        return solveTab(prices);
    }
};