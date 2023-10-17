int minJumps(vector<int> &arr,int n) 
{
    // Write your code here.

    int jumpsCount = 0;

    int ma = arr[0];
    if(n==1) {
        // if(arr[0] == 0) return 0;
        // else return 1;
        return 0;
    }
    vector<int> dp(n+1, 0);
    dp[0] = ma;
    for(int i = 1; i < n-1; i++){
        dp[i] = max(dp[i-1], i+arr[i]);
        if(dp[i] == i) return -1;
        if(ma == i){
            jumpsCount++;
            ma = dp[i];
            // cout<<"Updating MA :: "<<ma << " :: "<<jumpsCount<<endl;
        }
    }
    // cout<<"The DP is :: "<<endl;
    // for(auto x: dp) cout<<x<<"\t";
    return jumpsCount+1;
}