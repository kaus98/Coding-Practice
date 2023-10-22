int floorSqrt(int n)
{
    // Write your code here.

    int low = 1;
    int high = n;

    int ans = -1;

    while(low <= high){
        int mid = (low+high)/2;
        int value = mid*mid;

        if(value <= n){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}
