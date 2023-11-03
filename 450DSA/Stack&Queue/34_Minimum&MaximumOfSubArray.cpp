#include <bits/stdc++.h> 

void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

long long f(vector<int> &arr, int n, int k){

	deque<int> sm;
	deque<int> gr;

	int i = 1;
	// sm.push_back(arr[0]);
	gr.push_back(arr[0]);
	sm.push_back(arr[0]);

	while(i < k){
		//Condition for Greater Element.
		if(arr[i] > gr.front()){
			//We can remove all the elements from Queue
			while(!gr.empty()) gr.pop_front();
			gr.push_back(arr[i]);
		} else {
			while(arr[i] > gr.back()) gr.pop_back();
			gr.push_back(arr[i]);
		}
		//Condition for Smaller Element.
		if(arr[i] < sm.front()){
			//We can remove all the elements from Queue
			while(!sm.empty()) sm.pop_front();
			sm.push_back(arr[i]);
		} else {
			while(arr[i] < sm.back()) sm.pop_back();
			sm.push_back(arr[i]);
		}

		i++;
	}	
	long long su = 0;
	su += ( sm.front() + gr.front());
	int j = k;
	i = 0;
	while(j < n){
		if(arr[i] == gr.front()) gr.pop_front();
		if(arr[i] == sm.front()) sm.pop_front();

		if(gr.empty()) gr.push_back(arr[j]);
		else if(arr[j] > gr.front()){
			while(!gr.empty()) gr.pop_front();
			gr.push_back(arr[j]);
		} else{
			while(arr[j] > gr.back()) gr.pop_back();
			gr.push_back(arr[j]);
		}

		//For Smaller Element
		if(sm.empty()) sm.push_back(arr[j]);
		else if(arr[j] < sm.front()){
			while(!sm.empty()) sm.pop_front();
			sm.push_back(arr[j]);
		} else {
			while(arr[j] < sm.back()) sm.pop_back();
			sm.push_back(arr[j]);
		}


		i++;
		j++;
		// cout<<gr.front()<<"\t";
		su += (sm.front() + gr.front());
	}
	// cout<<endl;
	return su;
}

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	return f(nums, n, k);
}
