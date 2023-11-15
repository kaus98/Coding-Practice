#include <bits/stdc++.h> 
/********************************
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

********************************/

void splitCircularList(Node *head)
{
    // Write your code here.

    if(head == NULL) return;

    Node* slow = head;
    Node* fast = head;

    while(fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* end = fast->next;

    fast = slow->next;
    slow->next = head;
    end->next = fast;

}
