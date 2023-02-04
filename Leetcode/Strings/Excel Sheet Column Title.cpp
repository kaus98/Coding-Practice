class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        
        while(columnNumber--){
            int temp = columnNumber%26;
            ans.push_back(temp+'A');
            columnNumber = (columnNumber-temp)/26;
            cout<<"Adding : "<< ans<<endl;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
