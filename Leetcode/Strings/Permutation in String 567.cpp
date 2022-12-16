class Solution {
public:
  bool checkInclusion(string s1, string s2) {
        // Beats 99.8% of Solution
        
        int m[26] = {0};
        int n[26] = {0};
        int len1 = s1.length();
        int len2 = s2.length();

        if (len2 < len1) return false;

        for(int i=0; i < len1; i++){
            m[s1[i]-'a']++;
            n[s2[i]-'a']++;
        }
        int l = 0;
        int count = 0;

        while(l<26){
            if(n[l] == m[l]) count++;
            // else break;
            l++;
            }
        if(count == 26) return true;
        int j = len1;
        int k = 0;
        
        int sk, sj;

        while(j < len2){

            sk = s2[k] - 'a';
            sj = s2[j] - 'a';

            
            if(n[sk]-- == m[sk]) count--;
            if(n[sk] == m[sk]) count++;


            if(n[sj]++ == m[sj]) count--;
            if(n[sj] == m[sj]) count++;

            if(count == 26) return true;

            k++;j++;
        }
        return false;
    }
    bool checkInclusion92(string s1, string s2) {
        // Beats 92% of Solution
        
        int m[26] = {0};
        int n[26] = {0};
        int len1 = s1.length();
        int len2 = s2.length();

        if (len2 < len1) return false;

        for(int i=0; i < len1; i++){
            m[s1[i]-'a']++;
            n[s2[i]-'a']++;
        }
        int l = 0;
        int count = 0;
        while(l<26){
            if(n[l] == m[l]) count++;
            else break;
            l++;
            }
        if(count == 26) return true;

        int j = len1;
        int k = 0;
        
        while(j < len2){
            n[s2[k]-'a']--;
            n[s2[j]-'a']++;
            k++;j++;
            
            l = 0;
            count = 0;
            while(l<26){
                if(n[l] == m[l]) count++;
                else break;
                l++;
            }
            if(count == 26) return true;
            
        }
        return false;
    }
};
