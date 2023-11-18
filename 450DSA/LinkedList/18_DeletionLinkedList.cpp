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

Node* deleteNode(Node* head, int key) 
{
    // Write your code here.

    //Give us the 3 cases to solve
    
    if(head == NULL) return NULL;

    if(head->data == key && head->next == head) return NULL;

    //If present in first place
    if(head->data == key){
        Node* temp = head;

        while(temp->next != head) temp = temp->next;
        Node* toDeleteNode = head;

        head = head->next;
        temp->next = head;
        delete(toDeleteNode);
        return head;
    }

    //If Present in middle place or Last
    
    Node* curr = head->next;
    Node* prev = head;


    while(curr != head){
        if(curr->data == key){
           prev->next = curr->next;
           delete(curr);
           return head;
        } else {
           prev = curr;
           curr = curr->next;
        }
    }

    
}