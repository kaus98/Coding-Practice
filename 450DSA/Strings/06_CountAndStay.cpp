class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        return count(n-1 , "1");
    }

    string count(int n, string str){
        if(n==0) return str;
        int len = str.size();

        char temp;
        int i = 0;
        string res;
        while(i < len){
            temp = str[i];
            int counter = 1;
            while(i < len-1 && str[i]==str[i+1]) {counter++; i++;}
            res = res.append(to_string(counter));
            res.push_back(str[i]);

            i++;
        }
        return count(n-1, res);
    }
};