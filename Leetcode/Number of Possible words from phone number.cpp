// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
class Solution {
public: 
    void solve (string digits, int index, string str, vector<string>& ans, string mappings[] ){
        if (index >= digits.length()){
            ans.push_back(str);
            return ;
        }
        //Process to convert Char to Int
        int digit = digits[index] - '0';
        for(int i = 0; i< mappings[digit].length(); i++){
            str.push_back(mappings[digit][i]);
            solve(digits, index+1, str, ans, mappings);
            str.pop_back();
        }

        return ;
    }

    vector<string> letterCombinations(string digits) {
        // Problem can be solved with Recursion
        string mappings[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        
        if (digits.length() == 0){
            return ans;
        }
        
        int index = 0;
        string str = "";
        
        solve(digits, index, str, ans, mappings);
        return ans;
    }
};