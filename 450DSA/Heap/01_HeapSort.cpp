#include <bits/stdc++.h> 

void MaxHeapify(vector<int> &arr, int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int index = i;

    if(left >= n) return;

    if(left < n && arr[index] < arr[left]) index = left;

    if(right < n && arr[index] < arr[right]) index = right;

    if(index!=i){
        swap(arr[index], arr[i]);
        MaxHeapify(arr, index, n);
    }    

}

void Heapify(vector<int> &arr, int n){
	
	for(int i = n/2-1; i >= 0; i--){
		MaxHeapify(arr, i, n);
	}


}
vector<int> heapSort(vector<int>& arr, int n) {
	// Write your code here.
	Heapify(arr, n);

	for(int i = n-1; i>0; i--){
		swap(arr[i], arr[0]);

		MaxHeapify(arr, 0, i);

	}
	return arr;
}