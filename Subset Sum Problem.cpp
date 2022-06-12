#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int subsetRecursive(int numbers[], int n, int sum){
    if (sum==0) return true;
    if (n==0) return false;
    if (numbers[n-1] <= sum) return subsetRecursive(numbers, n-1,sum) || subsetRecursive(numbers, n-1,sum-numbers[n-1]);
    else return subsetRecursive(numbers, n-1, sum);
};

int subsetRecursiveMemory(int numbers[], int n, int sum, int** t){
    if (sum==0) return 1;
    if (n==0) return 0;
    
    if (t[n][sum]!= -1) return t[n][sum];
    
    if (numbers[n-1] <= sum) return t[n][sum] = max(subsetRecursiveMemory(numbers, n-1, sum, t), subsetRecursiveMemory(numbers, n-1,sum-numbers[n-1], t));
    else return t[n][sum] =  subsetRecursiveMemory(numbers, n-1, sum, t);

};

int subsetTopDown(int number[], int n, int sum, int** t){
    for (int i=0; i< n+1; i++){
        for (int j=0; j< sum+1;j++){

            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;

        }
    }
    for (int i=1; i< n+1; i++){
        for (int j=1; j< sum+1;j++){
            if (number[i-1] <= j){
                t[i][j] = max(t[i-1][j], t[i-1][j-number[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
};

int countSubsetTopDown(int number[], int n, int sum, int** t){
    for (int i=0; i< n+1; i++){
        for (int j=0; j< sum+1;j++){

            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;

        }
    }
    for (int i=1; i< n+1; i++){
        for (int j=1; j< sum+1;j++){
            if (number[i-1] <= j){
                t[i][j] = t[i-1][j]+t[i-1][j-number[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
};

int equalSumPartition(int numbers[], int n){
    //Divide the Arry to 2 subsets that have equal sum

    int sum=0;
    int **t = new int*[n+1];

    
    for (int i = 0; i<n; i++) sum+=numbers[i];
    if ((sum%2) != 0) return 0;

    sum = sum/2;
    for (int i = 0; i < n+1; i++)  t[i] = new int[sum + 1];

    return subsetTopDown(numbers, n, sum, t);
};

int minimumDifferenceSubset(int numbers[], int n){
    //Concept here is to divide the array with subset of minimum difference.

    int sum=0;
    for (int i = 0; i<n; i++) sum+=numbers[i];

    int range = floor(sum/2);

    int **t = new int*[n+1];
    for (int i = 0; i < n+1; i++)  t[i] = new int[range + 1];

    for (int i=0; i< n+1; i++){
        for (int j=0; j< range+1;j++){

            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;

        }
    }
    for (int i=1; i< n+1; i++){
        for (int j=1; j< range+1;j++){
            if (numbers[i-1] <= j){
                t[i][j] = max(t[i-1][j], t[i-1][j-numbers[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    for( int i = range; i>=0; i--){
        if(t[n-1][i] ==1){
            return sum-(2*i);
        }
    }

};

int countSubsetWithDifference(int numbers[], int n, int diff, int ** t){
    int sum=0;
    for (int i = 0; i<n; i++) sum+=numbers[i];

    int range = (sum+diff)/2;

    int possibles = countSubsetTopDown(numbers, n, range, t);
    return possibles;
}

int targetSum(int numbers[], int n, int diff, int ** t){
    //We have to interchange any number to positive and negative and find the number of ways you can find the given sum
    //This problem is exactly the same as previous one
    return countSubsetWithDifference(numbers, n, diff, t);
}
int main(){
    int numbers[4] = {1,1,2,3};
    int sum = 1;
    int n = 4;
    int result;
    int **t = new int*[n+1];

    for(int i = 0; i < n+1; i++)  t[i] = new int[sum + 2];
    for (int i=0; i< n+1; i++) for (int j=0; j<sum+1; j++) t[i][j]=-1;

    cout <<"Subset Problem Solved with Recursion\n";
    result = subsetRecursive(numbers, n, sum);
    cout<<"If Subset is possible : "<< result;

    cout <<"\nSubset Problem Solved with Recursion keeping Memory\n";
    result = subsetRecursiveMemory(numbers, n, sum, t);
    cout<<"If Subset is possible : "<< result;
    // for(int i = 0; i< n+1; i++){
    //     for(int j = 0; j< sum+1; j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout <<"\nSubset Problem Solved with Top Down \n";
    result = subsetTopDown(numbers, n, sum, t);
    cout<<"If Subset is possible : "<< result;

    cout <<"\nCount Subset Problem Solved with Top Down \n";
    result = countSubsetTopDown(numbers, n, sum, t);
    cout<<"Number of Subset is possible : "<< result;

    cout <<"\nEqual Subset Problem Solved with Top Down \n";
    result = equalSumPartition(numbers, n);
    cout<<"Is Equal Subset Possible : "<< result;

    cout <<"\nDivide the Array with minimum Difference \n";
    result = minimumDifferenceSubset(numbers, n);
    cout<<"Result is  : "<< result;

    cout <<"\nCounts the subsets with difference \n";
    result = countSubsetWithDifference(numbers, n, sum, t);
    cout<<"Result is  : "<< result;
}