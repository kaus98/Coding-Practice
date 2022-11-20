class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k==1) return s.length();
        if(k > s.length()) return 0;
        if(s.length() == 0)return 0;
        int a[26] = {0};

        for(auto i: s){
            a[i-'a']++;
        }
        int ans = 0;
        int index = 0;
        while(true){
            if(index<s.length() && a[s[index] - 'a']<k) break;
            if(index >= s.length()) return s.length();
            index++;
        }

        int left = longestSubstring(s.substr(0, index), k);
        int right = longestSubstring(s.substr(index+1, s.length()) , k);


        return max(left, right);
    }
};
