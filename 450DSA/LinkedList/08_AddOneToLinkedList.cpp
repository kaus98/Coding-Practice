#include <bits/stdc++.h> 
/*****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

int solve(LinkedListNode<int> * root){
    if(root->data == -1) return 1;

    int carry = solve(root->next);
    root->data += carry;
    carry = root->data/10;
    root->data %= 10;

    return carry;
}

LinkedListNode<int>* addOneToList(LinkedListNode<int> *head)
{
    //Write your code here
    // LinkedListNode<int> *head;
    
    int carry = solve(head);
    if(carry>0){
        auto temp = new LinkedListNode<int>(1);
        temp->next = head;
        return temp;
    }
    return head;
}
