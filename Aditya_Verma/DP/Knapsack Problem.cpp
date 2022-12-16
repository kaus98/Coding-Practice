#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int knapsackRecursion(int weight[], int value[], int tw, int n){
    if(tw==0 || n==0){
        return 0;
    }

    if(weight[n-1] <= tw){
        return max(
            value[n-1] + knapsackRecursion(weight, value, tw-weight[n-1], n-1), 
            knapsackRecursion(weight, value, tw, n-1)
            );
    }

    else if (weight[n-1]>tw)
    {
        knapsackRecursion(weight, value, tw, n-1);
    }
    
};

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
        }

    }
    

    return t[n][wt];
};

int main()
{
    int n = 3;
    int value[] = {60,100,120};
    int weight[] = {10,20,30};
    int wt = 50;

    //Converting Recursion Problem to Memorization
    int **t = new int*[n+1];
    int max_profit = 0;

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


    cout <<"Knapsack Problem Solved with Recursion\n";
    max_profit = knapsackRecursion(weight, value, wt, n);
    cout<<"Max Profit is "<<max_profit<<"\n";

    cout <<"\nKnapsack Problem Solved with Recursion keeping Memory\n";
    max_profit = knapsackRecursionMemory(weight, value, wt, n, t);
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< wt+1; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Max Profit is "<<max_profit<<"\n";

    cout <<"\nKnapsack Problem Solved with Top Down DP\n";
    max_profit = knapsackTopDown(weight, value, wt, n, t);
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< wt+1; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Max Profit is "<<max_profit<<"\n";

    return 0;
};