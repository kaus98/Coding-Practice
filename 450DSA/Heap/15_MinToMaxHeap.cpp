
void Heapify(vector<int> &arr, int index){
	int left = 2*index+1;
	int right = 2*index+2;

	int current = index;
	if(left < arr.size() && arr[left] > arr[current]) current = left;
	if(right < arr.size() && arr[right] > arr[current]) current = right;

	if(current != index){
		swap(arr[index], arr[current]);
		Heapify(arr, current);
	} 
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
	for(int i = (n+1)/2; i >= 0; i--){
		Heapify(arr, i);
	}

	return arr;
}