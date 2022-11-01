class Solution {
public:
    int titleToNumber2(string columnTitle) {
        // Faster Approch. By ME
        int len = columnTitle.length();
        int ans = 0;
        long long sol = 1;
        
        while(len){
            ans += sol*(columnTitle[--len] - 'A'+1);
            sol*=26;
        }
        return ans;
    }
    int titleToNumber(string s) {
        //Slower Approch
        int ans=0;
        for(int i=0; i<s.size() ; i++){
            ans=26*ans+(s[i]-'@');
        }
        return ans;
    }
};
