#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int *top;
    int *head;

    int n, s;
    int free;

    NStack(int N, int S)
    {
        // Write your code here.
        n = N; // N Stacks are there to form
        s = S; // S is the size of Array

        top = new int[N];
        head = new int[S];
        arr = new int[S];
        free = 0;
        
        //Top init with -1;
        for(int i = 0; i < N; i++) top[i] = -1; // Top element of stack element
        for(int i = 0; i < S; i++) head[i] = i+1; // Next free Spot in Array
        head[S-1] = -1; // No next Free Spot
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.

        // x-> Element to Push
        // m-> Stack to push to
        // t-> top element for Stack Mth
        // h-> head element for Stack Mth
        // a-> That we will update here
        if(free == -1) return false;
        
        int temp = free;
        free = head[free]; // Next Available Space

        head[temp] = top[m-1];  // putting last element to head
        top[m-1] = temp; // Storing new space to top

        arr[temp] = x;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        // int temp = free;
        if(top[m-1] == -1) return -1;

        int temp = top[m-1];
        top[m-1] = head[temp];
        head[temp] = free;
        free = temp;
        return arr[temp];
    }
};