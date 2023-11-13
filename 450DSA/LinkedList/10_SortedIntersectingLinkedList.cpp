#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
      
Node* intersect_ll(Node* L1, Node *L2){

    Node * temp1 = new Node(0);
    Node * head = temp1;

    // Write your code here.
    while(L1 && L2){
        if(L1->data == L2->data){
            Node * temp2 = new Node(L1->data);
            temp1->next = temp2;
            temp1 = temp2;
            L1 = L1->next;
            L2 = L2->next;

        }
        else if(L1->data > L2->data){
            L2 = L2->next;
        } else {
            L1 = L1->next;
        }

    }   

    return head->next;
}