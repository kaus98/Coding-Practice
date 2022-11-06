class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;

        for(auto i : s){
            if(i == 93 || i == 125 || i == 41){
                if(ans.empty()) return false;
                else if(i==93 && ans.top() != 91) return false;
                else if(i==125 && ans.top() != 123) return false;
                else if(i==41 && ans.top() != 40) return false;
                ans.pop();
            }
            else{
                ans.push(i);
            }
        
        }
        if (ans.size() == 0) return true;
        return false;
    }
};
