/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int Solution::maxSubArray(const vector<int> &A) {

    int sum = 0;
    int max_sum = A[0];
    int n1 = A.size();
    
    for(int i = 1; i < n1; i++){
        sum+=A[i];
        
        max_sum = max(max_sum, sum);
        sum = max(0, sum);
    }
    
    return max_sum;
    
}
