#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int knapsackTopDown(int weight[], int value[], int wt, int n, int** t){
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< wt+1; j++){
            // Initilize the first Row and First Column as zero
            if(i==0 || j==0){
                t[i][j] = 0;
            }

            // Running DP Loop
            else if(weight[i-1] <= j){
                t[i][j] = max(t[i-1][j], value[i-1] + t[i-1][j-weight[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    

    return t[n][wt];
}


int main()
{
    int n = 4;
    int value[] = {1,4,5,7};
    int weight[] = {1,3,4,5};
    int wt = 7;

    //Converting Recursion Problem to Memorization
    int **t = new int*[n+1];

    for(int i = 0; i < n+1; i++){
        t[i] = new int[wt + 1];
    }
    // int t[n+1][wt+1];
    // memset( t, -1 ,sizeof(int)*(n+1)*(wt+1) ); // Initialize with -1

    
    int max_profit = knapsackTopDown(weight, value, wt, n, t);
    cout << max_profit;
    return 0;
};