#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    // Write your code here.
    map<char, int> m;

    for(int i = 0; i < n; i++){
        if(m.find(s[i]) == m.end()) m[s[i]] = 1;
        else m[s[i]]++;

        // m[s[i]]++;
    }

    vector<pair<char, int>> res;
    for (auto ii: m){
    // for (auto ii = m.begin(); ii != m.end(); ii++){
        if (ii.second > 1) {
            res.push_back(make_pair(ii.first, ii.second));
        }
    }
    return res;
}