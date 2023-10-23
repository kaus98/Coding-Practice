#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {

    // Write your code here.

    sort(arr.begin(),arr.end());

    int i,j,k,l;
    int sum =0;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            k=j+1;
            l=n-1;
            while(k<l)
            {
                sum=arr[i]+arr[j]+arr[k]+arr[l];
                if(sum==target) return "Yes";
                else  if(sum<target)  k++;
                else l--;
            }
        }
    }

    return "No";

}

 