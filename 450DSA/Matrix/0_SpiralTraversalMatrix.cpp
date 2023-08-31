#include <bits/stdc++.h> 
vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    // Write your code here.

    // cout<<"M and N value are : "<<m <<" , "<<n<<endl;
    m = matrix.size();
    n = matrix[0].size();

    int left = 0;
    int right = n;
    int top = 0;
    int bottom = m;
    vector<int> ans;

    while(left < right && top < bottom){
        for(int i = left; i < right; i++) {ans.push_back(matrix[top][i]);}
        top++;

        for(int i = top; i < bottom; i++) ans.push_back(matrix[i][right-1]);
        right--;

        if (top < bottom) {
            for(int i = right-1; i >= left; i--) ans.push_back(matrix[bottom-1][i]);
            bottom--;
        }

        if (left < right) {
            for(int i = bottom-1; i >= top; i--) ans.push_back(matrix[i][left]);
            left++;
        }


    }
    return ans;

}