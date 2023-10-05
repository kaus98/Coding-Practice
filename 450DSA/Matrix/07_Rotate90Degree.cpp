#include <bits/stdc++.h> 
void inplaceRotate(vector<vector<int>> &inputArray)
{
    // Write your code here.
    //First we will rotate along the diagnol and then along y axis from middle

    int n = inputArray.size();
    for(int i = 0; i < n; i++) for(int j = 0; j < (n-i-1); j++) swap(inputArray[i][j] , inputArray[n-j-1][n-i-1]);

    //Rotate from center y Axis
    for(int i = 0; i < n; i++) for(int j = 0; j < n/2; j++) swap(inputArray[i][j], inputArray[i][n-j-1]);

}