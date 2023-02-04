class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        bool bl = true;
        int len = 0;
        for(int i = size-1; i>-1; i--){
            if (!isspace(s[i])){
                bl = false;
                len ++;
            }
            else{
                if(!bl){
                    break;
                }
            }
        }
        return len;
    }
};