bool validStackPermutation(vector<int> &first, vector<int> &other){
	// Write your code here.

	int i = 0, j = 0;

	stack<int> st;

	for(int i = 0; i < first.size(); i++){
		st.push(first[i]);

		while(!st.empty() && st.top() == other[j]){
			j++;
			st.pop();
		}
	}

	if(!st.empty()) return false;
	return true;
}