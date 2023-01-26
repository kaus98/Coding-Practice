#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int AllocatePages(vector<int> arr, int head, int tail, int min){

    int bin = (head+tail)/2;
    cout<<"Searching for : "<<bin<<endl;
    int sum = 0;
    int num = 1;
    int mini =0;

    for(auto x: arr){
        if(sum+x > bin){
            sum = x;
            num++;
            if(num>min) break;
        }
        else{
            sum+=x;
            mini = max(mini, sum);
        }
    }

    if(num <= min && mini == bin) return bin;
    if(num > min) return AllocatePages(arr, bin+1,tail, min);
    else return AllocatePages(arr, head, bin, min);
}

int getSum(vector<int> arr){
    int sum = 0;
    for(auto x: arr){
        sum+= x;
    }

    return sum;
}

int main(){
    vector<int> arr = {10,20,30,40,10,10};
    int gs = getSum(arr);
    int result = AllocatePages(arr, 0, gs,2);

    cout << "Result is : " << result;
}