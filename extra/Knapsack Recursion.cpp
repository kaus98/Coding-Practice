#include <iostream>
#include <vector>
#include <string>

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
    
}

int main()
{
    int n = 3;
    int value[] = {60,100,120};
    int weight[] = {10,20,30};
    int wt = 50;

    int max_profit = knapsackRecursion(weight, value, wt, n);
    cout << max_profit;
}