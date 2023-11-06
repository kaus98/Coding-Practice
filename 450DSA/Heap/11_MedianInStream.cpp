#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	//WE WILL KEEP THE MAX QUEUE TO BE GREATER AND MIN QUEUE TO BE SMALLER
	int temp;
	vector<int> res;
	minq.push(arr[0]);
	res.push_back(arr[0]);
	
	for(int i = 1; i < n; i++){

		minq.push(arr[i]);
		// cout<<"Pushing the Element : "<<arr[i]<<endl;
		while(minq.size() > maxq.size() ){
			// cout<<"Ist Iteration :: "<< minq.top()<<endl;
			maxq.push(minq.top());
			minq.pop();

		}
		while(minq.size() > 0 && maxq.size() > 0 && minq.top() < maxq.top()){
			// cout<<"2nd Iteration :: "<<minq.top()<<" :: "<<maxq.top()<<endl;
			temp = maxq.top();
			maxq.pop();
			maxq.push(minq.top());
			minq.pop();
			minq.push(temp);
		}

		if(minq.size() == maxq.size()) res.push_back((minq.top()+maxq.top())/2);
		else {
			if(minq.size() > maxq.size()) res.push_back(minq.top());
			else res.push_back(maxq.top());
		}
	}

	return res;
}
