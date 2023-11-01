#include <bits/stdc++.h>
bool checkStringExpression(string str) {
  // Write your code here.

  stack<char> s;
  int count = 0;
  for (int i = 0; i < str.length(); i++){
	  if(str[i] == '('){
		  s.push('(');
	  } else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
		  s.push('s');
	  } else if(str[i] == ')'){
		  if(s.top() == '('){
			  s.pop();
			  count++;
		  } else if(s.top() == 's'){
			  while(s.top() == 's') s.pop();
			  s.pop();
		  }
		  else {
			  cout<<"1 case"<<endl;
		  }
	  } else{
		  continue;
	  }
  }
  return count;
}