#include <bits/stdc++.h> 
int getMinPathSum(vector<vector<int>> &m)
{
    //  Write your code here.

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
             if(i==0 || j==0){
                 //Side case handling
                if(i==0 && j==0) {
                    continue;
                } else if (i == 0) {
                    m[i][j] = m[i][j - 1] + m[i][j];
                } else {
                    m[i][j] = m[i-1][j] + m[i][j];
                } 
             }else{
                 m[i][j] = m[i][j] + min({
                     m[i-1][j],
                     m[i][j-1],
                     m[i-1][j-1]
                 });
             }
        }
    }

    return m[m.size()-1][m[0].size()-1];
}