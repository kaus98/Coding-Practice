class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int i = 0;
        int len = s.length();
        // Comparsions with Int rather than Characters can make huge difference in Time of Running.
        while(i<len)
            {
            if(s[i] != 32){
                while(s[i]!=32 && i<len)
                    i++;
                count++;
            
            }
            else i++;
        }
        return count;
    }
    
    int countSegments1(string s) {
        //Wrong way to solve this problem
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ' && i<s.length()-1 && s[i+1]!= ' ')
                count++;
            
        }
        if(count) return count+1;
        return count;
    }
};
