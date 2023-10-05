
#include<bits/stdc++.h>>


int HistogramArea(vector<int> &result){
    int n = result.size();
	vector<int> l2r(n, -1);
	vector<int> r2l(n, n);
	stack<int>  st;

	//Going Left to Right
	// cout<<"Array is :: \t";
	for(int i = 0; i < n; i++){
		// cout<<result[i]<<"\t";
		if(st.empty()) st.push(i);

		else {
			int top = st.top();

			while(result[top] >= result[i]){
				st.pop();
				if(st.empty()) break;
				top = st.top();
			}

			if(!st.empty())l2r[i] = st.top();
			st.push(i);
		}
	}

	while(!st.empty()) st.pop();

	for(int i = n-1; i >= 0; i--){
		if(st.empty()) st.push(i);

		else {
			int top = st.top();

			while(result[top] >= result[i]){
				st.pop();
				if(st.empty()) break;
				top = st.top();
			}

			if(!st.empty()) r2l[i] = st.top();
			st.push(i);
		}
	}

	int mre = INT_MIN;
	// cout<<endl;

	for(int i = 0; i < n; i++){
		// cout<<"\t "<<r2l[i]<<" "<<l2r[i]<<endl;
		mre = max(mre, (r2l[i] - l2r[i] -1)*result[i]);
	}
	// cout <<" -> "<<mre<<endl;
	return mre;
}


int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.

	vector<int> result(m, 0);
	int mres = INT_MIN;

	for(int i = 0; i < mat.size(); i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j]==0) result[j] = 0;
			else result[j]++;
		}

		//This become histogram problem
		mres = max(mres, HistogramArea(result));
	}

	return mres;
}