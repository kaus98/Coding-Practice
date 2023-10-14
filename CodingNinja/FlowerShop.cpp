// https://www.codingninjas.com/studio/problems/flower-shop_625694?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Write your code here
    int n;
    cin>>n;
    int vec[n];
    int ele;

    for(int i = 0; i < n;i++){
        cin>>vec[i];
    }

    sort(vec, vec+n);
	int count = 1;
	int buy = vec[0];

    for(int i = 0; i < n; i++){
        if(vec[i] >= buy && vec[i] <= buy+4){
            continue;
        } else{ 
			count++;
			buy = vec[i];
        }
    }
    cout<<count;
    return 0;
}