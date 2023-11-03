#include <bits/stdc++.h> 
int firstUniqueCharacter(string s , int n) {
	// Write your code here.
	map<char, int> mp;
	queue<int> qu;
	int i = 0;
	for(i = 0; i < n; i++) {
		mp[s[i]]++; 
		if(mp[s[i]] == 1) qu.push(i);
	}
	int ind = -1;
	while(!qu.empty()) {
		if(mp[s[qu.front()]] == 1){
			return qu.front()+1;
		}
		qu.pop();
	}

	return -1;
}
