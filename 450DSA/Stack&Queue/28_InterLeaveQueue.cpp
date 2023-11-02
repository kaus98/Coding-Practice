#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.

    queue<int> tp;
    int n = q.size()/2;
    for(int i = 0; i < n; i++){
        tp.push(q.front());
        q.pop();
    }

    for(int i = 0; i < n; i++){
        
        q.push(tp.front());
        tp.pop();
        q.push(q.front());
        q.pop();

    }
}