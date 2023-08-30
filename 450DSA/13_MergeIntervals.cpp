class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>>  result;
        result.push_back(intervals[0]);
        vector<int> temp;
        for(int i=0; i<intervals.size(); i++){
            if(result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }

        }

        return result;
    }
};