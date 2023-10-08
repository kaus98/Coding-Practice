#include <bits/stdc++.h> 
string reArrangeString(string &s)
{
	// Write your code here.
	map<char, int> result;
        
    for(int i = 0; i < s.size(); i++){
        result[s[i]]++;    
    }
    
	priority_queue<pair<int,char>> pq;
    for(auto it:result){
        pq.push(make_pair(it.second,it.first));
    }

    int size1 = (s.size()+1)/2;
    int top_max = pq.top().first;
    if(top_max > size1) return "not possible";
    
    int first;
    char second;
    int i = 0;

	while(!pq.empty()){
        first = pq.top().first;
        second = pq.top().second;
        
        while(first>0){
            s[i] = second;
            i+=2;
            if(i >= s.size()) i = 1;
            first--;
        }
        pq.pop();
	}
	return s;
	
}

    // int maxi = INT_MIN+1;
	// char res;
    // for(auto x: result){
	// 	if(x.second > maxi){
	// 		maxi = x.second;
	// 		res = x.first;
	// 	}
// 		cout<<"Coutn : "<<x.first<<" : "<<x.second<<endl;
    // }
    // int size = (s.size()+1)/2;
    // cout<<"Max count found as "<<maxi <<" "<< size <<endl;
        
    // if(maxi > size) return "-1";
    // return "1";
