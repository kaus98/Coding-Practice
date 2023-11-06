#include <bits/stdc++.h> 
string getMinimumSum(vector<int> &arr, int n)
{
	// Write your code here.

	if(arr.size() == 1) return to_string(arr[0]);
	
	priority_queue<int> pq;

	for(auto x: arr) pq.push(x);

	string s1 = "";
	int t1, t2;
	int sum, res, carry;
	carry = 0;
	while(!pq.empty()){

		t1 = pq.top(); pq.pop();
		if(pq.empty()) t2 = 0;
		else {
			t2 = pq.top(); pq.pop();
		}
		
		sum = t1+t2+carry;
		if(sum!= 0) s1 += (to_string(sum%10));
		carry = sum/10;
	}
	while(carry != 0){
		s1 += to_string(carry%10);
		carry /= 10;
	}
	

	reverse(s1.begin(), s1.end());
	if(s1=="") return "0"; // Special case handling for 0 values input
	return s1;

}