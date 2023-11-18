#include <bits/stdc++.h> 
/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/

DLLNode* rotateDLL(DLLNode* head, int k) 
{
    // Write your code here.
	DLLNode* end = head;

	while(end->next != NULL) end = end->next;

	end->next = head;
	head->prev = end;

	while(k>1){
		k--;
		head = head->next;
	}

	DLLNode* temp = head->next;
	temp->prev = NULL;
	head->next = NULL;

	return temp;
}