class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length()-1;
        int lenb = b.length()-1;
        int extra = 0;
        string str = "";
        
        while(true){
            int sum = 0;
            // String Checking
            if(lena>-1){
                if (a[lena] == '1'){
                    sum++;
                }
                lena--;
            }
            if(lenb>-1){
                if (b[lenb] == '1'){
                    sum++;
                }
                lenb--;
            }
            
            // Computation
            sum+=extra;
            if(sum%2 == 0) str.push_back('0');
            else str.push_back('1');
            extra = (sum>1)?1:0;
            
            // Exit Loop
            if(lena==-1 && lenb==-1){
                if(extra==1){
                    str.push_back('1');  
                }
                break;
            }
        }
        // Reverse the String
        string str2 = "";
        for(int i = str.length()-1; i>-1;i--){
            str2.push_back(str[i]);
        }
        return str2;
    }
};