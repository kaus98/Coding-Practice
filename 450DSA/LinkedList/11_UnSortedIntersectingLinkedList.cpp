/****************************************************************

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
            }w
        };

*****************************************************************/


//Return the Length of LinkedList
int getLen(Node *root){
    if(root == NULL) return 0;

    return 1 + getLen(root->next);
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int first = getLen(firstHead);
    int second = getLen(secondHead);

    while(first > second){
        firstHead = firstHead->next;
        first--;
    }
    while(second > first){
        secondHead = secondHead->next;
        second--;
    }

    while(firstHead && secondHead){
        if(firstHead && firstHead == secondHead) return firstHead;
        else {
            firstHead = firstHead->next;
            secondHead = secondHead->next;
        }

    }
    return NULL;
}
