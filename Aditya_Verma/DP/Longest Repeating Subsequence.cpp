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

int LongestCommonRepeatingSubsequence(string& str1, string& str2, int n, int m, int ** t){
    for (int i = 0; i<=m; i++){
        for (int j = 0; j<=n; j++){
            t[i][j] = 0;
        }
    }
    for (int i = 1; i<=m; i++){
        for (int j = 1; j<=n; j++){
            if((str1[i-1] == str2[j-1]) && (i!=j)){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
    
        }
    }
    return t[m][n];
}

int main(){
    string str1 = "abaaabcefff";

    int m = str1.size();
    cout<<"String 1 : "<< str1 << " ("<<m<<")\n";

    int **t = new int*[m+1];
    for(int i = 0; i < m+1; i++) t[i] = new int[m + 1];
    for(int i = 0; i < m+1; i++) {for (int j = 0; j<m+1 ; j++) {t[i][j]=-1;}}
    

    int lcs = LongestCommonRepeatingSubsequence(str1, str1, m, m, t);
    display2d(t, m+1, m+1);
    cout<<"Longest Repeating Subsequence with Top Down : "<< lcs;

}