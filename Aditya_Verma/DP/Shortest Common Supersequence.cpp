#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void display2d(int ** arr, int n, int m){

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }   
        cout<<"\n";
    }
}

int LCSTopDown(string& str1, string& str2, int n, int m, int ** t){
    for (int i = 0; i<=m; i++){
        for (int j = 0; j<=n; j++){
            if(i==0){
                t[i][j] = j;
            }
            else if(j==0){
                t[i][j] = i;
            }
            else{
                t[i][j] = 0;
            }                
        }
    }
    for (int i = 1; i<=m; i++){
        for (int j = 1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = 1 + min(t[i][j-1], t[i-1][j]);
            }
    
        }
    }
    return t[m][n];
}

int LCSTopDownAnotherApproach(string& str1, string& str2, int n, int m, int ** t){
    //Shortest sequence Another Approach (sum of length - lcs)
    for (int i = 0; i<=m; i++){
        for (int j = 0; j<=n; j++){
            t[i][j] = 0;
        }
    }
    for (int i = 1; i<=m; i++){
        for (int j = 1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
    
        }
    }
    return (m+n) - t[m][n];
}

string PrintShortestCommonSubsequence(string& str1, string& str2, int n, int m, int ** t){
    // Creating the 2-D array to filter the data
    for (int i = 0; i<=m; i++){
        for (int j = 0; j<=n; j++){
            t[i][j] = 0;
        }
    }
    for (int i = 1; i<=m; i++){
        for (int j = 1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
    
        }
    }


    string arr = "";
    int i = m;
    int j = n;

    while(i>0 || j>0){
        if(i==0){
            arr += str2[j-1];
            j--;
        }
        else if (j == 0){
            arr += str1[i-1];
            i--;
        }
        else if(str1[i-1] == str2[j-1]){
            arr += str1[i-1];
            i--;
            j--;
        }
        else{
            if (t[i-1][j] > t[i][j-1]){
                i--;
                arr+= str1[i];
            }
            else{
                j--;
                arr += str2[j];
            }
        }
    }
    reverse(arr.begin(), arr.end());
    return arr;
}

int main(){
    string str1 = "abcefd";
    string str2 = "bhekdf";

    int m = str1.size();
    int n = str2.size();

    cout<<"String 1 : "<< str1 << " ("<<m<<")\n";
    cout<<"String 2 : "<< str2 << " ("<<n<<")\n";

    int **t = new int*[m+1];
    for(int i = 0; i < m+1; i++) t[i] = new int[n + 1];
    for(int i = 0; i < m+1; i++) {for (int j = 0; j<n+1 ; j++) {t[i][j]=-1;}}

    int lcs = LCSTopDown(str1, str2, n, m, t);
    display2d(t, m+1, n+1);
    cout<<"Shortest Common Supersequence with Top Down : "<< lcs << "\n";

    int str = LCSTopDownAnotherApproach(str1, str2, n, m, t);
    display2d(t, m+1, n+1);
    cout<<"Shortest Common Supersequence with Top Down : "<< str << "\n";

    string result = PrintShortestCommonSubsequence(str1, str2, n, m, t);
    cout<<"Subsequence is : "<< result<< "\n";

}