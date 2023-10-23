int minSwaps(vector<int> &arr)
{
	// Write your code here.
	// Create a Pair of Point and index

	vector<pair<int, int>> mp;
	for(int i = 0; i < arr.size(); i++){
		mp.push_back(make_pair(arr[i], i));
	}

	sort(mp.begin(), mp.end());

	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		if(mp[i].second != i){
			swap(mp[i] , mp[mp[i].second]);
			cnt++;
			i--;
		}
	}
	return cnt;
}