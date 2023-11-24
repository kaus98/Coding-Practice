// You are given a binary string A(i.e. with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean change character 0 to 1 and vice-versa.

// Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.

// If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

// NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.



vector<int> Solution::flip(string A) {
    
    int start = 0, end = 0, mx = 0, mxSum = 0;
    int a = -1, b = -1;
    
    
    for(int i = 0; i  < A.size(); i++){
        if(A[i] == '1') mx--;
        else mx++;
        
        if(mx < 0){
            mx = 0;
            start = i+1;
        }
        
        if(mx > mxSum){
            mxSum = mx;
            a = start;
            b = i;
        }
    }

    vector<int> result;
    if(a == -1) return result;
    else {
        result.push_back(a+1);
        result.push_back(b+1);
        return result;
    }
}
