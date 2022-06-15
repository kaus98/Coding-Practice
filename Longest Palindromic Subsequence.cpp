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
    return t[m][n];
}

int MinimumNumberOfDeletions(string & str1, string& str2, int n, int m, int **t){
    // Minimum number of deletions is same as Minimum number of insertions for palindrome.
    
    int result = LCSTopDown(str1,str2, n, m, t);
    return m-result;
}

string printLCSTopDown(string& str1, string& str2, int n, int m, int ** t){
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
    // int flag = t[m][n] + 1;
    string arr = "";

    //Using the method described in Video
    int i = m;
    int j = n;
    while(i!=0 && j!= 0){
        if(str1[i-1] == str2[j-1]){
            // strcat(arr, str2[j-1]);
            arr += str1[i-1];
            i--;
            j--;
        }
        else{
            if (t[i-1][j] > t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(arr.begin(), arr.end());
    return arr;

}


int main(){
    string str = "acefvfa";
    string rec;
    rec = str;
    reverse(rec.begin(), rec.end());
    int m = str.size();

    cout<<"String 1 : "<< str << " ("<<m<<")\n";
    cout<<"String 2 : "<< rec << " ("<<m<<")\n";

    int **t = new int*[m+1];
    for(int i = 0; i < m+1; i++) t[i] = new int[m + 1];
    for(int i = 0; i < m+1; i++) {for (int j = 0; j<m+1 ; j++) {t[i][j]=-1;}}

    int lcs = LCSTopDown(str, rec, m, m, t);
    display2d(t, m+1, m+1);
    cout<<"Longest Common Solution with Top Down : "<< lcs;

    int dell = MinimumNumberOfDeletions(str, rec, m, m, t);
    cout<<"Minimum number of deletions with Top Down to make perfect Palindrome : "<< dell;

    string result = printLCSTopDown(str, rec, m, m, t);
    cout<<"\nLongest Common Solution with Top Down : "<< result;

}