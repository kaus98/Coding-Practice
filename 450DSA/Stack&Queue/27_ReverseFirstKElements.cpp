#include <bits/stdc++.h> 


void firstReverse(queue<int> &q, int k){
    if(k == 0) return;

    int temp = q.front();
    q.pop();
    firstReverse(q, k-1);
    q.push(temp);
}

void secondReverse(queue<int> &q, int k){
    if(k==0) return;
    
    q.push(q.front());
    q.pop();
    secondReverse(q, k-1);
}


void reverse(queue<int> &queue,int k)
{
    // Write your code here.
    firstReverse(queue, k);
    secondReverse(queue, queue.size() - k);
}
