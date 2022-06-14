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
int LCSRecussive(string& str1, string& str2, int n, int m){
    if (m==0 || n==0){
        return 0;
    }

    if(str1[m-1] == str2[n-1]){
        return 1+LCSRecussive(str1, str2, n-1, m-1);
    }
    else{
        return max(LCSRecussive(str1, str2, n, m-1), LCSRecussive(str1, str2, n-1, m));
    }
}

int LCSRecussiveMemory(string& str1, string& str2, int n, int m, int ** t){
    if (m==0 || n==0){
        return 0;
    }

    if (t[m][n]!=-1){
        return t[m][n];
    }

    if(str1[m-1] == str2[n-1]){
        return t[m][n] = 1+LCSRecussiveMemory(str1, str2, n-1, m-1, t);
    }
    else{
        return t[m][n] = max(LCSRecussiveMemory(str1, str2, n, m-1, t), LCSRecussiveMemory(str1, str2, n-1, m, t));
    }
}

int LCSTopDown(string& str1, string& str2, int n, int m, int ** t){
    cout<<"Starting the Process";
    for (int i = 0; i<=m; i++){
        for (int j = 0; j<=n; j++){
            t[i][j] = 0;
        }
    }
    cout<<"Completed Init";
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
    return t[m][n];
}


int main(){
    string str1 = "abcef";
    string str2 = "acefvfa";

    int m = str1.size();
    int n = str2.size();

    cout<<"String 1 : "<< str1 << " ("<<m<<")\n";
    cout<<"String 2 : "<< str2 << " ("<<n<<")\n";

    int lcs = LCSRecussive(str1, str2, n, m);

    cout<<"Longest Common Solution : "<< lcs << "\n";

    int **t = new int*[m+1];
    for(int i = 0; i < m+1; i++) t[i] = new int[n + 1];
    for(int i = 0; i < m+1; i++) {for (int j = 0; j<n+1 ; j++) {t[i][j]=-1;}}
    
    lcs = LCSRecussiveMemory(str1, str2, n, m, t);
    display2d(t, m+1, n+1);
    cout<<"Longest Common Solution with Memory : "<< lcs;

    lcs = LCSTopDown(str1, str2, n, m, t);
    display2d(t, m+1, n+1);
    cout<<"Longest Common Solution with Top Down : "<< lcs;

}