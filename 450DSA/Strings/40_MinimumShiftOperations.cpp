#include <bits/stdc++.h> 
//Getting Timeout for One TestCase
//Should use Array rather than Map
int minShift(string &s1, string &s2)
{
	// Write your code here

	if(s1.size() != s2.size()) return -1;

	// unordered_map<char,int> m1, m2;
	list<int> m1
	for(int i = 0; i < s1.size(); i++) { m1[s1[i]]++; m2[s2[i]]++;}
	for(auto x: m1) if(m2[x.first] != x.second) return -1;

	int p1 = s1.size()-1;
	int p2 = s2.size()-1;
	int count = 0;
	while(p1>=0 && p2>=0) {
		if(s1[p1] != s2[p2]) {p1--;count++;}
		else {p1--;p2--;}
	}

	return count;

}