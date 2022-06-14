#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void display1d(int arr[]){
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Size of Array"<<n+1<<"\n";
    for (int i =0; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout<<"\n";
}

int coinChangeGreedyApproach(int coins[], int w, int n){
    // Not always the best solution, Can be wrong
    sort(coins, coins+n);
    int count = 0;

    for (int i = n-1; i>=0; i--){
        if(coins[i]<= w){
            count++;
            w-=coins[i];
            i++;
        }
    }

    return count;
}

int coinChange1D(int coins[], int w, int n){
    int arr[w+1];
    arr[0] = 0;
    for (int i=0; i <= w; i++){
        arr[i] = INT_MAX-1;   
    }

    for(int i = 1; i <= w; i++){
        for (int j = 0; j<n; j++){
            if (coins[j] <= i){
                int change = arr[i-coins[j]];
                if (change != (INT_MAX-1) && (change+1)<arr[i]){
                    arr[i] = change+1;
                }
            }
        }
    }

    if(arr[w] == (INT_MAX-1)){
        return -1;
    }
    else{
        return arr[w];
    }
}


int main()
{
    int n = 3;
    int value[] = {3,1,2};
    int wt = 7;

    //Converting Recursion Problem to Memorization
    int **t = new int*[n+1];
    int max_profit = 0;

    cout<<"Greedy approach to solve the Coin Change"<<"\n";
    max_profit = coinChangeGreedyApproach(value, wt, n);
    cout<<"Minimum Number of coins required are : "<<max_profit;

    cout<<"1-D Approach to solve the problem with top-Down "<<"\n";
    

    // for(int i = 0; i < n+1; i++){
    //     t[i] = new int[wt + 1];
    // }

    // cout <<"\nMinimum number of coins to return the Change Solved with Top Down DP\n";
    // max_profit = coinChangeTopDown(value, wt, n, t);
    // for(int i = 0; i< n+1; i++){
    //     for(int j = 0; j< wt+1; j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // cout<<"Max Ways is "<<max_profit<<"\n";

    //Rod Cutting Problem is extension of Unbounded Knapsack problem
    return 0;
};