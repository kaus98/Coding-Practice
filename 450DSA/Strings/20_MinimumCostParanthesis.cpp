#include <bits/stdc++.h> 
int findMinimumCost2(string str) {
  // Write your code here
  int counter = 0;
  int result = 0;
  if(str.size()%2 == 1) return -1;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '{') counter++;
    else counter--;
    if(counter < 0) {result++; counter = 0;}
  }
  result += (counter/2 + counter%2);
  return result;
}

int findMinimumCost(string s){
  int temp = 0, res = 0, n = s.size();
    if (n % 2 != 0)
        return -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '{')
            temp++;
        else {
            if (temp == 0) {
                res++;
                temp++;
            }
            else
                temp--;
        }
    }
    if (temp > 0)
        res += temp / 2;
    return res;
}