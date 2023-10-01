
bool isvalid(int** arr, int n, int m, int x, int y){
   return (x>=0 && x < n && y>=0 && y < m && arr[x][y] == 1);
}
void dfs(int** arr, int n, int m, int x, int y){
   int mx[8]={-1,-1,0,1,1,1,0,-1};
   int my[8]={0,1,1,1,0,-1,-1,-1};

   int nx, ny;
   for(int i = 0; i < 8; i++){
      nx = x+mx[i];
      ny = y+my[i];

      if(isvalid(arr, n, m, nx, ny)){
         arr[nx][ny] = 2;
         dfs(arr, n, m, nx, ny);
      }
   }

}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int count = 0;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(arr[i][j] == 1){
            count++;
            dfs(arr, n, m, i, j);
         }
      }
   }

   return count;
}
