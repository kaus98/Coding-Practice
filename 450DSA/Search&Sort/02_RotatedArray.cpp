
int binarySearch(vector<int>& nums, int i, int j, int target) {
    while (i <= j) {  // Change the condition to include 'i == j'
        int mid = i + (j - i) / 2;
        if (nums[mid] == target) return mid;
        if (target < nums[mid]) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.'
    if(n==1){
        if(arr[0] == k) return 0;
        return -1;
    } 

    if(arr[0] < arr[arr.size()-1]) {
        return binarySearch(arr, 0, arr.size()-1, k);
    }

    int start = 0;
    int end = arr.size()-1;

 
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] < arr[mid-1]) {
            int tp1 = binarySearch(arr, 0, mid-1, k);

            if(tp1 != -1) return tp1;

            int tp2 = binarySearch(arr, mid, arr.size()-1, k);
            if(tp2 != -1) return tp2;

            break;
        }

        if(arr[mid] >= arr[0]) start = mid+1;
        else end = mid-1;
    }

    return -1;
}
