#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int coinChangeTopDown(int weight[], int wt, int n, int** t){
    for (int i=0; i< n+1; i++){
        for (int j=0; j< wt+1;j++){

            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;

        }
    }
    for(int i = 1; i< n+1; i++){
        for(int j = 1; j< wt+1; j++){
            if(weight[i-1] <= j){
                t[i][j] = t[i-1][j] + t[i][j-weight[i-1]];
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
    int value[] = {1,2,3};
    int wt = 5;

    //Converting Recursion Problem to Memorization
    int **t = new int*[n+1];
    int max_profit = 0;

    for(int i = 0; i < n+1; i++){
        t[i] = new int[wt + 1];
    }

    cout <<"\nNumber of ways to return the Change Solved with Top Down DP\n";
    max_profit = coinChangeTopDown(value, wt, n, t);
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< wt+1; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Max Ways is "<<max_profit<<"\n";

    //Rod Cutting Problem is extension of Unbounded Knapsack problem
    return 0;
};