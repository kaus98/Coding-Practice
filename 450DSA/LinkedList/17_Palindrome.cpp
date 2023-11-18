#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

// Size of Linked List

int sizeList(LinkedListNode<int> *root){
    if(root == NULL) return 0;

    return sizeList(root->next) + 1;
}

LinkedListNode<int> *reverse(LinkedListNode<int>* head){

    LinkedListNode<int> * prev = NULL;
    LinkedListNode<int> * next;

    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    //Steps to follow
    
    //Find the Mid of Linked List
    //Reverse the Second half of List
    //Compare One by One
    
    int list = sizeList(head);
    if(list == 0 || list == 1) return true;
    LinkedListNode<int> *tp = head;

    int i = 0;
    while( i < (list-1)/2){
        tp = tp->next;
        i++;
    }
    // cout<<"The Middle Element is :: "<<tp->data<<endl;

    LinkedListNode<int> *mid = reverse(tp->next);
    // cout<<"Mid :: "<<mid->data<<endl;

    while(mid!=NULL && head != NULL){
        if(mid->data == head->data){
            // cout<<"Comp :: "<<mid->data<<" : "<<head->data<<endl;
            mid = mid->next;
            head = head->next;
        }else {
            return false;
        }
    }

    return true;



}