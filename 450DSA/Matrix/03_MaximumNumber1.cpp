
int getSum(vector<vector<int>> &matrix, int column, int n, int m){
    
    int count = 0;

    for(int i = 0; i < n; i++){
      if (matrix[i][column]) {
        count++;
        if(count>1) return 2;
      }
    }
    return count;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int start = 0;
    int last = m-1;
    int mid = (start+last)/2;

    while()



}