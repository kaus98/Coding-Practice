#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here

   int count0 = 0;
   int count1 = 0;
   int count2 = 0;
   int i = 0;

   while(i<n){
      if(arr[i] == 0)count0++;
      if(arr[i] == 1)count1++;
      if(arr[i] == 2)count2++;
      i++;
   }
   i=0;
   count1 += count0;
   count2 += count1;

   while(i < count0) arr[i++] = 0;
   while(i < count1) arr[i++] = 1;   
   while(i < count2) arr[i++] = 2;
}
