// An integer interval [X, Y] (for integers X < Y) is a set of all consecutive integers from X to Y, including X and Y.

// You are given a 2D array A with dimensions N x 2, where each row denotes an interval.

// Find the minimum size of a set S such that for every integer interval Z in A, the intersection of S with Z has a size of at least two.

bool comp(vector<int>  &A, vector<int> &B){
    if(A[1] == B[1]) return A[0] > B[0];
    return A[1] < B[1];
}
int Solution::setIntersection(vector<vector<int> > &A) {
    
    sort(A.begin(), A.end(), comp);
    
    vector<int> result;
    
    result.push_back(A[0][1]-1);
    result.push_back(A[0][1]);
    
    for(int i = 0; i < A.size(); i++){
        
        if(result[result.size() - 1] < A[i][0]){
            result.push_back(A[i][1]-1);
            result.push_back(A[i][1]);
        }
        else if(result[result.size() - 1] == A[i][0]){
            result.push_back(A[i][1]);
        } 
        else if(result[result.size() - 2] < A[i][0] && result[result.size() - 1] >= A[i][0]){
            result.push_back(A[i][1]);
        } 
    }
    
    return result.size();
}
