
bool isPossible(vector<int> &boards, int k, int mid){
    int sum = 0;
    int painters = 1;

    for(auto x: boards){
        if(sum+x <= mid){
            sum += x;
        } else {
            sum = x;
            painters++;
        }
    }

    if(painters > k) return false;
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int start = -1, end = 0, mid, ans = -1;

    for(auto x: boards){
        end += x;
        start = max(start, x);
    }

    while(start <= end){
        mid = start + (end-start)/2;

        if(isPossible(boards, k, mid)){
            ans = mid;
            end = mid-1;
        } else start = mid+1;
    }

    return start;
}