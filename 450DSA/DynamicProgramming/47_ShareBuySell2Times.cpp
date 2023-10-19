class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i = 0;
        int j = 0;
        int n = prices.size();

        vector<int> left(prices.size(), 0);
        vector<int> right(prices.size(), 0);

        int left_min = INT_MAX-1;
        int right_max = -1;

        // Moving left to right

        cout<<"Left Iteration is: ";
        left_min = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] <= left_min) left_min = prices[i];
            // else {
            //     left[i] = max(left[i-1], prices[i] - left_min);
            // }
            left[i] = max(left[i-1], prices[i] - left_min);

        }
        for(int i = 0; i < n; i++){
            cout<<left[i]<<" ";
        }
        cout<<"\nRight Iteration is: "  ;    

        right_max = prices[n-1];
        for(int i = n-2; i>-1; i--){
            if(prices[i] >= right_max) right_max = prices[i];
            // else {
            //     right[i] = max(right[i+1], right_max - prices[i]);
            // }
            right[i] = max(right[i+1], right_max - prices[i]);

        }
        for(int i = 0; i < n; i++){
            cout<<right[i]<<" ";
        }

        int res = 0;
        for(int i = 0; i<n; i++){
            res = max(res, left[i]+right[i]);
        }
        return res;
    }
};