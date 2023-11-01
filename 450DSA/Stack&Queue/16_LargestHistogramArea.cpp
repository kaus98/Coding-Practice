#include<bits/stdc++.h>

 vector<int> smallestLeftIndex(vector<int> & heights){

  stack<int> st;
  vector<int> leftI;
  for(int i = 0; i < heights.size(); i++){
    while(st.empty() != true && st.top()!= -1 && heights[st.top()] >= heights[i])st.pop();

    if(st.empty()) leftI.push_back(-1);
    else leftI.push_back(st.top());

    st.push(i);
  }

  // cout<<"Checking the leftIndex :: "<<endl;
  // for(auto x: leftI)  cout<<x<<"\t";
  // cout<<endl;

  return leftI;
 }

vector<int> smallestRightIndex(vector<int>& heights){
  stack<int> st;
  vector<int> rightI = heights;
  for(int i = heights.size()-1; i >= 0; i--){
    while(st.empty() != true && st.top()!= heights.size() && heights[st.top()] >= heights[i]) st.pop();

    if(st.empty()) rightI[i] = heights.size();
    else rightI[i] = st.top();

    st.push(i);
  }

  // cout<<"Checking the RightIndex :: "<<endl;
  // for(auto x: rightI) cout<<x<<"\t";
  // cout<<endl;
  return rightI;
}

 int largestRectangle(vector < int > & heights) {
   // Write your code here.

   vector<int> leftI = smallestLeftIndex(heights);
   vector<int> rightI = smallestRightIndex(heights);

   int mx = INT_MIN+1;

   for(int i = 0; i < heights.size(); i++){
     mx = max(mx, heights[i] * (rightI[i] - leftI[i] - 1));
   }
   return mx;
 }
