
# include<bits/stdc++.h>
int maximumAreaSquare(vector<vector<int>> &MAT, int n, int m) {
  // Write your code here.

  int sum = 0;

  for (int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          if(i!=0 && j!=0 && MAT[i][j] == 1){
              MAT[i][j] = 1 + min({
                  MAT[i-1][j-1],
                  MAT[i-1][j],
                  MAT[i][j-1]
              });
          }
          sum = max(sum , MAT[i][j]);
      }
  }

  return sum*sum;
}
