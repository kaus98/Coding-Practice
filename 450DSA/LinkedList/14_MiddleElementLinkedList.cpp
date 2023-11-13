/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

int getLen(Node *root){
    if(root == NULL) return 0;

    return 1 + getLen(root->next);
}

Node *findMiddle(Node *head) {
    // Write your code here

    int hei = getLen(head);
    int total = hei;

    while(total-- > (hei+1)/2)
        head = head->next;


    return head;

}

