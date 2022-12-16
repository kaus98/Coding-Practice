bool compare(string a, string b){
        return a+b > b+a;
    }
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto i: nums) str.push_back(to_string(i));

        sort(str.begin(), str.end(), compare);

        string ans;
        for(auto j: str) ans+=j;
        if(ans[0]=='0') return "0";
        return ans;
    }
};
