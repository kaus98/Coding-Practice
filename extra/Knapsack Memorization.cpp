#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int knapsackRecursionMemory(int weight[], int value[], int tw, int n, int** t){
    if(tw==0 || n==0){
        return 0;
    }

    if(t[n][tw] != -1){
        return t[n][tw];
    }

    if(weight[n-1] <= tw){
        t[n][tw] = max(
            value[n-1] + knapsackRecursionMemory(weight, value, tw-weight[n-1], n-1, t), 
            knapsackRecursionMemory(weight, value, tw, n-1, t)
            );
    }

    else if (weight[n-1]>tw)
    {
        t[n][tw] = knapsackRecursionMemory(weight, value, tw, n-1, t);
    }
    return t[n][tw];

};


int main()
{
    int n = 3;
    int value[] = {60,100,120};
    int weight[] = {10,20,30};
    int wt = 50;

    //Converting Recursion Problem to Memorization
    int **t = new int*[n+1];

    for(int i = 0; i < n+1; i++){
        t[i] = new int[wt + 1];
    }
    // int t[n+1][wt+1];
    // memset( t, -1 ,sizeof(int)*(n+1)*(wt+1) ); // Initialize with -1

    for (int i=0; i< n+1; i++){
        for (int j=0; j<wt+1; j++){
            t[i][j]=-1;
        }
    }

    int max_profit = knapsackRecursionMemory(weight, value, wt, n, t);
    cout << max_profit;
    return 0;
};