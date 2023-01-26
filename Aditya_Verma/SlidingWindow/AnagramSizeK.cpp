#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int AnagramSizeK(string base, string ana, int k){
    map<char, int> count;
    if(ana.size() != k) return -1;
    for(auto x: ana){
        if(count.find(x) != count.end()) count[x] += 1;
        else count[x] = 1;
    }
    for(auto j = count.begin(); j != count.end(); j++){
        cout<<"\tKey: "<<j->first<<" Value: "<<j->second<<endl;
    }
    auto i = 0;
    auto temp = 0;
    auto result = 0;
    while(i < base.size()){
        cout<<"Inserting Value" << base[i]<<endl;
        if (count.find(base[i]) != count.end()) count[base[i]] -= 1;

        if (i >= k-1){
            cout<<"Checking for Value"<<base[i-k]<<endl;
            if(count.find(base[i-k]) != count.end()) count[base[i-k]] += 1;
            temp = 0;
            for(auto j = count.begin(); j != count.end(); j++){
                cout<<"\tKey: "<<j->first<<" Value: "<<j->second<<endl;
                if(j -> second == 0) temp += 1;
            }
            if(temp == k) result += 1;
        }
        i++;
    }

    return result;
}

int main(){

    auto base = "abcbcaihgabccbabca";
    auto ana = "bca";

    auto result = AnagramSizeK(base, ana, 3);

    cout<<"Working Result is : "<<result;
}