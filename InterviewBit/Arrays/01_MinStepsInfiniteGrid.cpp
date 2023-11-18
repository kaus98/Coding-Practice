/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */

//  You are in an infinite 2D grid where you can move in any of the 8 directions

//  (x,y) to 
//     (x-1, y-1), 
//     (x-1, y)  , 
//     (x-1, y+1), 
//     (x  , y-1),
//     (x  , y+1), 
//     (x+1, y-1), 
//     (x+1, y)  , 
//     (x+1, y+1) 

// You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.

int coverPoints(int* A, int n1, int* B, int n2) {
    int x1,x2,y1,y2,x,y;
    int steps = 0;
    int i;
    for(i=1;i<n1;i++){
        x = abs(A[i-1] - A[i]);
        y = abs(B[i-1] - B[i]);
        
        steps += abs(x-y);
        if(x>y){
            steps+=y;
        }
        else{
            steps+=x;
        }
    }
    return steps;
}
