#include <bits/stdc++.h>

void insertSort(stack<int> &stack, int element){
	if(stack.empty()) {stack.push(element); return;}

	if(stack.top() <= element) {stack.push(element); return;}


	int temp = stack.top();
	stack.pop();

	insertSort(stack, element);
	stack.push(temp);
	return;
}


void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;
	int temp = stack.top();
	// cout<<"Popping the top :: "<<temp<<endl;
	stack.pop();
	sortStack(stack);

	insertSort(stack, temp);
}

