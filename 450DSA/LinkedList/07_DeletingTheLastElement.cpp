#include <bits/stdc++.h> 
/****************************************************************

Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

*****************************************************************/

Node *delAddLastNode(Node *head){
	// Write your code here.

    if(head == NULL || head->next == NULL) return head;
    Node *next = head;
    Node *prev = NULL;

    while(next->next){
        prev = next;
        next = next->next;
    }

    prev->next = NULL;
    next->next = head;

    return next;

}