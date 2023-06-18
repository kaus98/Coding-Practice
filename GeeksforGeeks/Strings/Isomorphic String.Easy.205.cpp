class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> abc;
        map<char, char> cba;

        if(s.length() != t.length()){
            return false;
        }

        // int i = 0;
        for(int i = 0; i < s.length(); i++){
            if (abc.find(s[i]) == abc.end()){
                if(cba.find(t[i]) == cba.end()){
                    abc[s[i]] = t[i];
                    cba[t[i]] = s[i];

                }
                else{
                    return false;
                }
                
            }
            else{
                if(abc[s[i]] != t[i] || cba[t[i]] != s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
