#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int getUniques(int a[]){
    // int n = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    cout << "Value of Array is : ";
    for(int x = 0; x < 26; x++){
        cout<<a[x]<<"\t";
        if (a[x] > 0) sum++;
    }
    cout<<endl;

    return sum;
}

int LongestSubstringK(string s, int k){

    int i = 0;
    int j = 0;
    int a[26] = {0};

    int n = s.size();
    int largest = 0;
    int uni = 0;
    while(j < n){
        // cout<<"Starting with J : "<<j<<endl;
        a[s[j] - 'a']++;
        uni = getUniques(a);
        cout << "Unique Value is : "<<uni<< "\t"<<s[j]-'a'<<endl;
        // cout<<"Unique Characters are Uni : "<<uni<<endl;
        j++;
        if (uni == k) largest = max(largest, (j-i+1));
        
        while(uni > k){
            a[s[i] - 'a']--;
            cout<<"Decresing the Value : "<<a[s[i] - 'a']<<endl;
            uni = getUniques(a);
            i++;
        }

        if (uni == k) largest = max(largest, (j-i));
    }

    return largest;
}

int main(){

    string s = "aabccabecabcaashasd";
    int result = LongestSubstringK(s, 3);
    cout << "Longest SubString is : "<<result;
    return 0;
}
