class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> result;
        result.push_back(envelopes[0][1]);

        for(int i = 1; i < envelopes.size(); i++){
            if(result.back() < envelopes[i][1]) result.push_back(envelopes[i][1]);
            else {
                int index = lower_bound(result.begin(), result.end(), envelopes[i][1]) - result.begin();
                result[index] = envelopes[i][1];
            }
        }
        return result.size();
    }
};