#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int n){
	
   // Write your code here
   n += 1;

   int middle;
   if(n%2 == 1){
      //Off Number of elements
      middle = n/2;
   } else {
      //Even number of elements
      middle = (n/2); 
   }

   stack <int> arr;
   int temp;
   while(inputStack.size() != middle){
      // temp = inputStack.top();
      arr.push(inputStack.top());
      inputStack.pop();
      // cout<<"Putting to ARR :: "<<arr.top()<<" :: "<<arr.size()<<" :: "<<inputStack.size()<<endl;
   }

   arr.pop();

   while(!arr.empty()){
      inputStack.push(arr.top());
      arr.pop();
   }
   
}