/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    Node* start = head;
    Node* end = head;
    vector<pair<int, int>> result;


    while(end->next != NULL) end = end->next;

    while(start->data <  end->data){
        int tp = start->data + end->data;

        if(tp == k) {
            result.push_back({start->data, end->data});
            start = start->next;
            end = end->prev;
        }
        else if(tp>k) end = end->prev;
        else start = start->next;
    }

    return result;
}
