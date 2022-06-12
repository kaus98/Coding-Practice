#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

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


int equalSumPartition(int number[], int n){
    int sum=0;
    int **t = new int*[n+1];

    
    for (int i = 0; i<n; i++) sum+=number[i];
    if ((sum%2) != 0) return 0;

    sum = sum/2;
    for (int i = 0; i < n+1; i++)  t[i] = new int[sum + 1];

    return subsetTopDown(number, n, sum, t);
};

int main(){
    int n = 4;
    int numbers[n] = {1,5,11,5};
    
    int result;
    

    cout <<"\nEqual Sum Partition Solved with Top Down \n";
    result = equalSumPartition(numbers, n);


    cout<<"If Partition is possible : "<< result;
}