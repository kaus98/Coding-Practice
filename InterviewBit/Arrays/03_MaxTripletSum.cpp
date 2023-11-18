// Given an array A containing N integers.

// You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

// If no such triplet exist return 0.

//Refer this
// https://www.youtube.com/watch?v=l_hPdol4CSU

//For Finding the Solution in right side
// Use the Maximum Element in right

// For Element in Left
// Use Set that keep the element in sorted value 
// the use Binary search to find the lower bound;

int Solution::solve(vector<int> &A) {
    
    set<int> st;
    vector<int> mx = A;
    
    for(int i = mx.size()-2; i >= 0; i--){
        mx[i] = max(mx[i], mx[i+1]);
    }
    
    int answer = 0;
    
    for(int i = 1; i < A.size()-2; i++){
        st.insert(A[i-1]);
        
        //Handling the Right Side
        if(mx[i+1] <= A[i]) continue;
        int rt = mx[i+1];
        
        //Handling the Left Side
        auto it = st.lower_bound(A[i]);
        if(it == st.begin()) continue;
        it--;
        
        int lt = *it;
        
        answer = max(answer , A[i]+rt+lt);
    }
    
    return answer;
    
}
