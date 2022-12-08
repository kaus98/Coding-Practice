class Solution {
public:
    vector<vector<int>> tri;

    int sumB(vector<vector<int>>& triangle, int row, int column, int sum){
        if(row == triangle.size()){
            return sum += triangle[row][column];
        }
        return min(sumB(triangle, row+1, column, sum+triangle[row][column]),sumB(triangle, row+1, column+1, sum+triangle[row][column]));
    }

    int sumB(int row, int column, int sum){
        if(row == tri.size()){
            return sum;
        }
        return min(sumB(row+1, column, sum+tri[row][column]),sumB(row+1, column+1, sum+tri[row][column]));
    }
    
    // Wrong Approach
    int sumB(int row, int column, int sum, int **t){
        if(row == tri.size()){
            return sum;
        }
        int leftSum, rightSum;
        if(t[row+1][column] == INT_MAX-1){
            leftSum = sumB(row+1, column, sum+tri[row][column], t);
            t[row+1][column] = leftSum;
        }
        else{
            leftSum = t[row+1][column];
        }

        if(t[row+1][column+1] == INT_MAX-1){
            rightSum = sumB(row+1, column+1, sum+tri[row][column], t);
            t[row+1][column+1] = rightSum;
        }
        else{
            rightSum = t[row+1][column+1];
        }

        return min(leftSum, rightSum);
    }

    int sumB2(int row, int column, int sum, int **t){
        if(row == tri.size()-1){
            return tri[row][column];
        }
        if(t[row][column] == INT_MAX-1){
            int i = min(sumB2(row+1, column, sum+tri[row][column], t), sumB2(row+1, column+1, sum+tri[row][column], t));
            t[row][column] = i;
            return i;
        }
        else{
            return t[row][column];
        }
    }

    int sumB3(int row, int column, int **t){
        // This is working Function
        if(row == tri.size()-1){
            return tri[row][column];
        }
        if(t[row][column] == INT_MAX-1){
            int i = tri[row][column] + min(sumB3(row+1, column, t), sumB3(row+1, column+1, t));
            t[row][column] = i;
            return i;
        }
        else{
            return t[row][column];
        }
    }

    
    int minimumTotal(vector<vector<int>>& triangle) {
        tri = triangle;

        int m = tri.size();
        int **t = new int*[m+1];
        for(int i = 0; i < m+1; i++) t[i] = new int[m + 1];
        for(int i = 0; i < m+1; i++) {for (int j = 0; j<m+1 ; j++) {t[i][j]=INT_MAX-1;}}
        
        return sumB3(0,0,t);
    }
};
