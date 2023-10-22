int LeftBinarySearch(vector<int> &arr, int k){
    int start = 0;
    int end = arr.size()-1;
    // int md = (start+end)/2;
    int mdh = -1;
    int md;
    while(start <=end){
        md = (start+end)/2;
        if(arr[md] == k) {mdh = md; end = md-1;}
        if(arr[md] > k) end = md-1;
        if(arr[md] < k) start = md+1;
    }
    return mdh;
}

int RightBinarySearch(vector<int> &arr, int k){
    int start = 0;
    int end = arr.size()-1;
    // int md = (start+end)/2;
    int mdh = -1;   
    int md;

    while(start <=end){
        md = (start+end)/2;
        if(arr[md] == k) {mdh = md; start = md+1;}
        if(arr[md] > k) end = md-1;
        if(arr[md] < k) start = md+1;
    }
    return mdh;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here

    int i;
    int j;
    i = LeftBinarySearch(arr, k);
    j = RightBinarySearch(arr, k);

    return make_pair(i,j);
 }

