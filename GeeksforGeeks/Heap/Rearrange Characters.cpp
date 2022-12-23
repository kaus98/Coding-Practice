// https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, char> pi;

string RemoveCharactersHeap(string str)
{
    unordered_map<char, int> um;
    unordered_map<char, int>::iterator it;

    priority_queue<pi> maxHeap;

    // Sort by the Frequency of Number
    for (auto i : str)
    {
        if (um.find(i) != um.end())
            um[i]++;
        else
            um.insert(make_pair(i, 1));
    }

    for (it = um.begin(); it != um.end(); it++)
    {
        cout<<"Pushing : "<<it->first << " Value : "<<it->second <<endl;
        maxHeap.push(make_pair(it->second, it->first));
    }

    int count = 0;
    char ch = 'a';
    string st = "";
    // Method will be to pop one the push that to temp and then pop another add that to string and push previous to Stack
    pi temp = maxHeap.top();
    st.push_back(temp.second);
    maxHeap.pop();
    while (!maxHeap.empty())
    {   
        pi curr = maxHeap.top();
        count = curr.first;
        ch = curr.second;
        st.push_back(ch);
        maxHeap.pop();
        if (temp.first > 1)
            maxHeap.push(make_pair(temp.first-1 , temp.second));
        temp = curr;
    }
    return st;
}

string RemoveCharactersPattern(string str){
    unordered_map<char, int> um;
    unordered_map<char, int>::iterator it;

    priority_queue<pi> maxHeap;

    for (auto i : str)
    {
        if (um.find(i) != um.end())
            um[i]++;
        else
            um.insert(make_pair(i, 1));
    }

    for (it = um.begin(); it != um.end(); it++)
    {
        cout<<"Pushing : "<<it->first << " Value : "<<it->second <<endl;
        maxHeap.push(make_pair(it->second, it->first));
    }

    int i=0,j=0;
    // string ans = str;
    while(!maxHeap.empty()){
        pi temp = maxHeap.top();
        for(int k = 0; k < temp.first; k++){
            str[j]=temp.second;
            j+=2;
            if(j>=str.size()) j = 1;
        }
        maxHeap.pop();
    }
    return str;
}
int main()
{
    string str = "aabcccbdefggggghiizg";
    string st = RemoveCharactersPattern(str);
    cout << "New String is " << st;

    return 0;
}