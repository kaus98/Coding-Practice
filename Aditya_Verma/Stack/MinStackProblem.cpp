#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

void MinStackExtraSpace(vector<int> arr, vector<char> operations){
  stack<int> st;
  stack<int> mst;
  int i = 0;

  // Char Push -> P
  // Char Pop -> O
  // Char Min -> N

  for(int j = 0; j < operations.size(); j++){
    cout<<"Working On : "<<operations[j]<<endl;
    if(operations[j]=='P'){
      // Push Operations
      if(i<arr.size()) {
        st.push(arr[i]);
        if(mst.empty()) mst.push(arr[i]);
        else if(mst.top()>arr[i]) mst.push(arr[i]);
        i++;
      }
    }

    if(operations[j]=='O'){
      //Pop Operations
      int temp = st.top();st.pop();
      if(temp == mst.top()) mst.pop();
    }

    if(operations[j]=='N'){
      //Cout the top element of mst stack
      cout<<"* Min Element in Remaining Stack is : "<<mst.top()<<endl;
    }
  }
}


void MinStackWithoutExtraSpace(vector<int> arr, vector<char> operations){
  stack<int> st;
  int mst = INT_MAX-1;
  int i = 0;

  // Char Push -> P
  // Char Pop -> O
  // Char Min -> N

  for(int j = 0; j < operations.size(); j++){
    
    if(operations[j]=='P'){
      // Push Operations
      if(i<arr.size()) {
        st.push(arr[i]);
        if(mst == INT_MAX-1) mst = arr[i];
          
        else if(mst > arr[i]) {
          st.pop();
          st.push(2*arr[i] - mst);
          mst = arr[i];
        }
        i++;
      }
    }

    if(operations[j]=='O'){
      
      int temp = st.top();st.pop();
      if(temp < mst) mst = 2*mst-temp;
    }

    if(operations[j]=='N'){
      
      cout<<"* Min Element in Remaining Stack is : "<<mst<<endl;
    }
  }
} 
int main(){

  cout<<"Starting the Program"<<endl;
  vector<int> arr{5,4,5,4,1,-1};
  vector<char> operations{'P','P','N','P','O','P','N','P','N','P','N','P','O','N','P','P','N','O','N','O'};

  MinStackWithoutExtraSpace(arr,operations);
  return 0;
}