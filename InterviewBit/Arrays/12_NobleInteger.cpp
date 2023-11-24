// Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    
    for(int i = 0; i < A.size(); i++){
        if(i < A.size()-1 && A[i] == A[i+1]) continue;
        
        if(A.size() - i - 1 == A[i]) return 1;
    }
    
    return -1;
}
