#include <bits/stdc++.h> 

int MOD = 143;

int createHash(string s){
    int hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash += (s[i]-'0')%MOD;
    }
    return hash;
}

bool checkana(string s1, string s2){
    map<char, int> mp;
    
    for(int i = 0; i < s1.length(); i++){
        mp[s1[i]]++;
    }
    
    for(int i = 0; i < s2.length(); i++){
        mp[s2[i]]--;
        if(mp[s2[i]] == 0) mp.erase(s2[i]);
    }
    if (mp.size() == 0) return true;
    return false;
}


vector<vector<string> > groupAnagramsTogether(vector<string> &strList)
{
    // Write your code here.  

    //First Approach Without checking anything

    //Idea is to create hash of each such that we can directly compare hash and then check for if they are equal
    vector<int> ans(strList.size(), 0); // Vector of List to save the hash of value;
    vector<bool> check(strList.size(), true); // To store the value that are already used;
    vector<vector<string>> result; // To save the result and return this value;

    cout<<"The Created Hashes are : "<<endl;

    for(int i = 0; i < strList.size(); i++){
        ans[i] = createHash(strList[i]);
        cout<<"Value : "<<strList[i]<<" & Hash : "<<ans[i]<<endl;
    }
    for(int i = 0; i < strList.size(); i++){
        cout<<"Working on : "<<strList[i]<< " "<<check[i]<<" "<<ans[i] <<endl;
        if(check[i]) {
            cout<<"\tCheck Verified"<<endl;
            vector<string> temp;
            temp.push_back(strList[i]);
            
            for(int j = i+1; j < strList.size(); j++){
                if(check[j] && (ans[i] == ans[j]) && (strList[i].length() == strList[j].length()) && checkana(strList[i], strList[j]) ){
                    cout<<"\tCondition verified for : "<<check[j] << " "<<ans[j]<< " "<<strList[j]<<endl;
                    temp.push_back(strList[j]);
                    check[j] = false;
                }
                else{
                    cout<<"\t Condition Not Verified for : "<<check[j] << " "<<ans[j]<< " "<<strList[j]<<endl;
                }
            }
            result.push_back(temp);
            check[i] = false;
        }
    }

    return result;
}

