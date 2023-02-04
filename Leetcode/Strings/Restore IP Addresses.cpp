class Solution {
public:
    bool checkValidIP(string s) {
        int start=0, count = 0;
        cout<<"\n"<<"Checking for Sting s : "<<s<<"\n";
        for(int i=0;i <= s.length(); i++){
            if(s[i] == '.' || i == s.length() ){
                if(start == i) return false;
                count++;
                if(i-start > 3) return false;
                string sub = s.substr(start, i-start);
                int subInt = stoi(sub);
                cout<<"\nSub : "<<sub<<" SubInt : "<<subInt << " Start : "<<start << " I : "<<i << " Count : "<<count;                
                start = i+1;
                if((sub.length() == 0) ||(sub.length() > 1 && sub[0] == '0') || (subInt < 0 || subInt > 255)) return false;
            }
        }
        if(count == 4) return true;
        return false;
    }
    bool checkSub(string sub) {
        cout<<"\nChecking the Substring : "<< sub;
        if(sub.length() > 3 || sub.length() == 0) return false;
        int subInt = stoi(sub);
        if((sub.length() == 0) || (sub.length() > 1 && sub[0] == '0') || (subInt < 0 || subInt > 255)) return false;
        return true;
    }
    
    bool createIP(string s, int pos, int count, vector<string>  & ans){
        if (count >= 3){
            string subst = s.substr(pos, s.length());
            if(checkSub(subst) && checkValidIP(s)){
                cout<< "Pushing Back : "<<s; 
                ans.push_back(s);
                return true;
            }
            return false;
        }
        
        
        for(int i = 1; i <= 3; i++){
            if(pos+i > s.length()) return false;
            string subst = s.substr(pos, i);
            
            if(checkSub(subst)){
                string temp = s;
                createIP(temp.insert(pos+i,"."), pos+i+1,count+1,ans);
            }
        }
        
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans; 
        createIP(s, 0, 0, ans);
        return ans;
    }
};
