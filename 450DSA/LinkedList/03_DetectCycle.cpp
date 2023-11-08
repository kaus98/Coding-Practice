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

bool detectAndRemoveCycle(Node* head)
{
    // Write your code here
		Node *slow = head;
        Node *fast = head;
		Node *start;
		Node *prev;

        while(fast != NULL && fast->next != NULL){
			prev = slow;            
			slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
				start = head;
				while(start != fast){
					prev = fast;
					start = start->next;
					fast = fast->next;	
				}
				prev->next = NULL;
				return true;
			}
        }
        
        return false;
}
