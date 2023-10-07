#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.

	sort(arr.begin(), arr.end());

	vector<vector<int>> result;
	set<vector<int>> s;

	for( int i = 0; i < n; i++){
		int left = i+1;
		int right = n-1;

		while(left < right){
			int sum = arr[i] + arr[left] + arr[right];

			if(K == sum){
				vector<int> tri = {arr[i], arr[left], arr[right]};

                                if (s.find(tri) == s.end()) {
                                  result.push_back(tri);
                                  s.insert(tri);
                                }
                                left++;
                                right--;
                        } else if (K > sum)
                                left++;
                        else
                                right--;
                }
        }

	return result;
}