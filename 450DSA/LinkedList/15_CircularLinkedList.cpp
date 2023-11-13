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

bool circularLL(Node* head)
{
    // Write your code here

	Node* result = head;
	head = head->next;

	while(head != NULL){
		if(head == result) return true;
		head = head->next;
	}
	
	return false;
}
