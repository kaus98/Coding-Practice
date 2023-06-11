class Solution {
public:
    string reverseWords(string s) {
        int sLength = s.length();
        string result;
        
        int i = sLength;
        int j = sLength;

        while(i > -1){
            cout<<"Working on i : "<<i<<endl;
            if(s[i] != ' '){
                j = i;
                while(i>-1 && s[i] != ' ') i--;

                cout<<"Adding the value : "<<i+1<<" "<<j<<" "<<s.substr(i+1,j-i)<<endl;
                result += s.substr(i+1,j-i);
                // i--;
            }
            else {
                if(result.size() > 0 && result[result.size() - 1] != ' ') result.push_back(' ');
                i--;
            }
        }
        i = result.size()-1;
        while(result[i] == ' ') {result.pop_back();i--;}
        return result;
    }
};
