#include <bits/stdc++.h> 

void rec(int i,  vector<string> an, vector < vector < string > > & arr, vector < vector < string > > & ans){

    //Breaking Condition Here 
    if(i >= arr.size()) {ans.push_back(an); return;}

    for(int j = 0; j < arr[i].size(); j++){
        an.push_back(arr[i][j]);
        rec(i+1, an, arr, ans);
        an.pop_back();
    }

}

void createSentences(vector < vector < string > > & arr, vector < vector < string > > & ans) {
    // Write your code here.
    vector<string> an;
    rec(0, an, arr, ans);
}

