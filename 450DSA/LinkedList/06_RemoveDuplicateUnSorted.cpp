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

Node *removeDuplicates(Node *head)
{
    // Write your code here
    unordered_set<int> st;
    st.insert(head->data);
    Node *next = head->next;
    Node *prev = head;

    while(next){
        if(st.find(next->data) != st.end()){
            prev->next = next->next;
            next = next->next;
        } else {
            st.insert(next->data);
            prev = next;
            next = next->next;
        }
        
    }

    return head;
}