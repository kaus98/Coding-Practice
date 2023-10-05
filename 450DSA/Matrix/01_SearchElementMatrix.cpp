class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Starting to implement the 2D Matrix Transversal for Searching

        int start = 0;
        int end = matrix.size() * matrix[0].size()-1;


        while(start <= end){
            int mid = start + (end-start)/2;

            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) end = mid-1;
            else start = mid+1;

        }

        return false;

    }
};