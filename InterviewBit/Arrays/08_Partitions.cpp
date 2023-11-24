int Solution::solve(int A, vector<int> &B) {
    
    int sum = 0;
    
    for(auto x: B) sum+=x;
    if(sum%3 != 0) return 0;
    
    // if(sum%3 != 0) return -1;
    
    int oneSum = sum/3;
    int twoSum = oneSum*2;
    sum = 0;
    
    int xCount = 0;
    int ans = 0;
    
    for(int idx = 0; idx < A-1; idx++){
        sum += B[idx];
        
        if(sum == twoSum) ans+=xCount;
        if(sum == oneSum) xCount++;
        
    }
    
    return ans;
}
