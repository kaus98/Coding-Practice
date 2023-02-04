class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = "";
        for (int i=0;i < strs[0].length(); i++){
            char ch = strs[0][i];
            bool bl= true;
            for (int j = 0; j < strs.size(); j++){
                if (ch != strs[j][i]){
                    bl = false;
                    break;
                }
            }
            if(bl){
                temp.push_back(ch);
            }
            else{
                break;
            }
        }
        return temp;
    }
   
};