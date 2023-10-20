
// Refernce Video -> https://www.youtube.com/watch?v=dlKGCNVel6A&t=1617s
// Question Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
class Solution {
public:

    //Greedy Approach
    int greedy(vector<int> &prices){
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        return profit;
    }

    //This method uses the Recursion with Memorization
    int solve(vector<int> &prices, int index, int buy, vector<vector<int>> &dp){
        if(index == prices.size()) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        //If Allowed to buy
        if(buy){
            //Buying now
            int buyKaro = solve(prices, index+1, 0, dp) - prices[index];
            //Skipping now
            int skipKaro = solve(prices, index+1, 1, dp);

            return dp[index][buy]  = max(buyKaro, skipKaro);
        }
        
        //If Not Allowed to buy
        else{
            //Sell Karo
            int sellKaro = solve(prices, index+1, 1, dp) + prices[index];

            //Skip Karo
            int skipKaro = solve(prices, index+1, 0, dp);

            return dp[index][buy] = max(sellKaro, skipKaro);
        }

        return 0;
    }

    int solveTabular(vector<int> prices){
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, INT_MIN+10000));
        // 0 -> Dont have stock
        // 1 -> Already have stock
        dp[0][0] = 0;
        for(int i = 0; i < prices.size(); i++){
            dp[i+1][1] = max(dp[i][1] , dp[i][0]-prices[i]); //Buy  the stock
            dp[i+1][0] = max(dp[i][0] , dp[i][1]+prices[i]); //Sell the stock
        }

        return dp[prices.size()][0];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 1, dp);

        return greedy(prices);

        return solveTabular(prices);
    }
};