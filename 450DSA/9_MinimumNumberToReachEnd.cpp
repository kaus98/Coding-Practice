int minimumJumps(vector<int> &arr, int n)
{
    // write your code here

    if(n == 1) return 0;
    if(arr[0] == 0) return -1;
    int target = n-1;
    int start = 0;
    int temp = arr[0];
    int maximax = arr[0];
    int jumps = 1;
    for(int i = 1; i<n-1;i++){
        maximax = max(maximax, arr[i]+i);

        if (temp == i){
            jumps++;
            if(maximax == temp) return -1;
            temp = maximax;

        }


    }
    return jumps;
}   