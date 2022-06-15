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
    cout << "Number of Deltions to perform : "<< m-t[m][n] << "\n";
    cout << "Number of Insertions to perform : "<< n-t[m][n] << "\n";
    return t[m][n];
}


int main(){
    string str1 = "abcef";
    string str2 = "acefvfa";

    int m = str1.size();
    int n = str2.size();

    cout<<"String 1 : "<< str1 << " ("<<m<<")\n";
    cout<<"String 2 : "<< str2 << " ("<<n<<")\n";

    int **t = new int*[m+1];
    for(int i = 0; i < m+1; i++) t[i] = new int[n + 1];
    for(int i = 0; i < m+1; i++) {for (int j = 0; j<n+1 ; j++) {t[i][j]=-1;}}

    int lcs = LCSTopDown(str1, str2, n, m, t);
    display2d(t, m+1, n+1);
    cout<<"Longest Common Solution with Top Down : "<< lcs;


}