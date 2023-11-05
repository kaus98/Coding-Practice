
void MinHeapify(vector<int> &arr, int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int index = i;

    if(left >= n) return;

    if(left < n && arr[index] > arr[left]) index = left;

    if(right < n && arr[index] > arr[right]) index = right;

    if(index!=i){
        swap(arr[index], arr[i]);
        MinHeapify(arr, index, n);
    }    

}

void Heapify(vector<int> &arr, int n){
	
	for(int i = n/2-1; i >= 0; i--){
		MinHeapify(arr, i, n);
	}


}

int kthSmallestElement(vector<int>& arr, int n, int k) {
    // Write your code here

	// Write your code here.
	Heapify(arr, n);

	for(int i = n-1; i>n-k; i--){
		swap(arr[i], arr[0]);

		MinHeapify(arr, 0, i);

	}
	return arr[0];
}