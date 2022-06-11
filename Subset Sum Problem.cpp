#include <iostream>
#include <vector>
#include <string>
#include <cstring>

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

int main(){
    int numbers[6] = {1,2,3,4,5,6};
    int sum = 12;
    int n = 6;
    int result;
    int **t = new int*[n+1];

    for(int i = 0; i < n+1; i++)  t[i] = new int[sum + 2];
    for (int i=0; i< n+1; i++) for (int j=0; j<sum+1; j++) t[i][j]=-1;

    cout <<"Subset Problem Solved with Recursion\n";
    result = subsetRecursive(numbers, n, sum);
    cout<<"If Subset is possible : "<< result;

    cout <<"\nSubset Problem Solved with Recursion keeping Memory\n";
    result = subsetRecursiveMemory(numbers, n, sum, t);
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< sum+1; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"If Subset is possible : "<< result;

    cout <<"\nSubset Problem Solved with Top Down \n";
    result = subsetTopDown(numbers, n, sum, t);
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< sum+1; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"If Subset is possible : "<< result;
}