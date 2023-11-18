/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
//  Given an integer array A of size N.

// You have to pick exactly B elements from either left or right end of the array A to get the maximum sum.

// Find and return this maximum possible sum.

// NOTE: Suppose B = 4 and array A contains 10 elements then

//     You can pick the first four elements or can pick the last four elements or can pick 1 from the front and 3 from the back etc. you need to return the maximum possible sum of elements you can pick.

int solve(int* A, int n1, int B) {

    int mm = 0;
    
    int i,j;
    for(i = 0; i < B; i++){
        mm+=A[i];
    }
    int temp = mm;
    for(i=B-1, j = 1; i >= 0; i--, j++){
        temp = temp - A[i];
        temp = temp + A[n1-j];
        if(temp> mm){
            mm = temp;
        }
    }
    
    return mm;
}
