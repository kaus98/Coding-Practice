#include <bits/stdc++.h> 

int maxStackSum(vector<int> &stack1, vector<int> &stack2, vector<int> &stack3) 
{
    // Write your code here.
    int i = 0, j = 0, k = 0;

    int sum1 = 0, sum2 = 0, sum3 = 0;
    int sum;
    for(auto x: stack1) sum1+=x;
    for(auto x: stack2) sum2+=x;
    for(auto x: stack3) sum3+=x;

    while(true){
        if(sum1 == sum2 && sum2 == sum3) return sum;
        sum =  min({sum1, sum2, sum3});
        
        if(sum < sum1){
            sum1 -= stack1[i];
            i++;
        }

        if(sum < sum2){
            sum2 -= stack2[j];
            j++;
        }

        if(sum < sum3){
            sum3 -= stack3[k];
            k++;
        }
    
    }

    return 0;
}