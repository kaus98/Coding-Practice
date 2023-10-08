bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int pattern_size = pattern.size();
   int text_size = text.size();

   vector<vector<bool>> dp(pattern_size+1, vector<bool>(text_size+1, false));
   // vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));

   dp[0][0] = true;
   for(int i = 1; i <= pattern_size; i++){
      for(int j = 1; j <= text_size; j++){

         if(pattern[i-1] == "?") {
            //Depends on last element
            dp[i][j] = dp[i-1][j-1];
         } else if (pattern[i-1] == "*"){
            // Fill this entire row with True
            dp[i][j] = dp[i-1][j] | dp[i][j-1];

         } else if (pattern[i-1] == text[j-1]){
            dp[i][j] = dp[i-1][j-1];

         } else {
            dp[i][j] = false;
         }
      }
   }

   return dp[pattern_size][text_size];
}
