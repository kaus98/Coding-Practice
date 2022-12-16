class Solution {
public:
    bool cmp(int n, int x, bool cnd){
        if (cnd) return n < x;
        else return  n > x;
    }

    string maxValue(string n, int x) {
        bool cnd = true;
        if (n.length() > 0 && n[0] == '-')
            cnd = false;
        for(int i = 0; i < n.length(); i++){
            if(cmp(n[i]-'0' , x, cnd)) {
                n.insert(i, to_string(x));
                return n;
                }
        }
        n.insert(n.length(), to_string(x));
        return n;
    }
};
