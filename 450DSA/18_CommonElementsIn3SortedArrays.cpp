#include <bits/stdc++.h> 
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    // Write your code here

    int i = 0;
    int j = 0;
    int k = 0;
    set<int> count;
    while(i < a.size() && j < b.size() && k < c.size()){
        if (a[i]==b[j] && b[j]==c[k]){
            count.insert(a[i]);
            i++;j++;k++;
        }
        else if (a[i] < min(b[j], c[k])) i++;
        else if (b[j] < min(a[i], c[k])) j++;
        else k++;
    }
    vector<int> count1(count.begin(), count.end());
    return count1;
}