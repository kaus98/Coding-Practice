#include <bits/stdc++.h> 

void f(stack<int> & myStack, int x){

    if(myStack.empty()) { myStack.push(x); return; }

    int temp = myStack.top();

    myStack.pop();

    f(myStack, x);
    myStack.push(temp);

}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.

    f(myStack, x);
    return myStack;
}

