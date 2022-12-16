class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> ans;
        ans.push(-1);

        int count;
        int MAX = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') ans.push(i);
            else{
                ans.pop();
                if (ans.empty())ans.push(i);
            }
            MAX = max(MAX, i-ans.top());
        }
        return MAX;
    }
};
