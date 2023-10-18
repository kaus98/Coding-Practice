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

Node*findPartiton(Node*head, int x)
{
	// Write your code here
    Node* first = new Node(0);
    Node* second = new Node(0);

    Node* bkup1 = first;
    Node* bkup2 = second;


    while(head != NULL){
        if(head->data < x){
            first->next = head;
            first = first->next;
        } else{
            second->next = head;
            second = second->next;
        }
        head = head->next;
    } 
    second->next = NULL;
    first->next = bkup2->next;

    return bkup1->next;
    

}