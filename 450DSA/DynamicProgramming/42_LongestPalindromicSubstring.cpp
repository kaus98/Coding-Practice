

class Solution {
public:
    int TOTAL_COUNTERS = 0;
    int x = 0;
    int y = 0;
    int MAX = 0;

    int MS(string str){
        string str1 = "";

        int max = 0;
        for(float i = 0; i < str.size(); i+=0.5){

            int result = 0;
            int m,n;

            m = int(floor(i));
            n = int(ceil(i));

            while(m > -1 && n <= str.size()-1 && str[m] == str[n]){
                result = n - m + 1;

                
                if(result>max){
                    // cout<<"Reinitializing the Values : "<<i<<endl;
                    max = result;
                    x = m;
                    y = n;
                }
                if(m > 0 && n < str.size() - 1){
                    n++;
                    m--;
                }
                else{
                    break;
                }
                
            }

        }

        return 0;
    }

    string longestPalindrome(string str) {
        int _ = MS(str);
        string str2 = str.substr(x,y-x+1);
        return str2;
        
    }
};