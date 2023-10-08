#include <bits/stdc++.h> 

void result(vector<string> &res, string &s, string temp,int i, int j){
	// cout<<"Calling the result;"<<endl;
	if(i==s.size() ) {
		if(j==4 && temp.length() == s.length()+3) res.push_back(temp); 
		return;
	}
	int ss = s.size();
	for(int k = i; k < min(i+3, ss); k++){
		int tem = stoi(s.substr(i, k-i+1));
		string tm = "";
		
		if(tem>=0 && tem < 256){
			tm = temp + to_string(tem);
			// tm = temp + to_string(tem);
			if(j!=3) tm += ".";
			result(res, s, tm, k+1, j+1);
		}
	}
}

vector<string> generateIPAddress(string s)
{
	// Write your code here
	// cout<<"Starting the Code"<<endl;
	vector<string> res;
	result(res, s, "", 0, 0);

	return res;
}

