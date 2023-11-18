// There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.

// All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].

// Initially all lights are off.

// Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.


/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int solve(int* A, int n1, int B) {
    // For lets say given index light can go from +B to -B
    
    int i=0,cnt=0, k;
    while(i<n1){
        int lo=0, hi=n1-1;
        if((i-(B-1)) > 0) lo = i-(B-1);
        if((i+(B-1)) < n1-1) hi = i+(B-1);
        int c=0;
        for(k = hi; k>=lo; k--){
            if (A[k] == 1){
                cnt++;
                i = k+B;
                c++;
                break;
            }
        }
        
        if(c==0){
            return -1;
        }
         
    }
    
    return cnt;
    
}
