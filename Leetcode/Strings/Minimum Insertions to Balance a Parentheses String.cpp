class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<int> st;
        
        for (char c: s){
            if (c == '('){
                if(st.empty() || st.top()==2) st.push(2);
                else{
                    st.pop();st.push(2);
                    ans++;
                }
            }
            else{
                if(st.empty()){
                    st.push(1); ans++;
                }
                else {
                    if(st.top() == 1){
                        st.pop();
                    }
                    else{
                        st.pop();
                        st.push(1); 
                    }
                }
            }
        }
        
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        return ans;
    }       
};