int lcs(string &str1, string &str2){
    // Write your code here.
    vector<int> c(str2.size()+1, 0);
    vector<int> p(str2.size()+1, 0);

    int ma = INT_MIN+1;
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i-1] == str2[j-1]){
                if(i%2){
                    c[j] = 1+p[j-1];
                    ma = max(c[j], ma);
                } else{
                    p[j] = 1+c[j-1];
                    ma = max(p[j], ma);
                }
                
            } else {
                if(i%2) c[j] = 0;
                else p[j] = 0;
            }
        }
    }

    return ma;
}