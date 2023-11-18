/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

 Node* merge(Node* a, Node*b){
	 if(a == NULL) return b;
	 if(b == NULL) return a;
	 
	 Node* re;
	 if(a->data > b->data){
		 re = b;
		 re->child = merge(a, b->child);
	 } else {
		 re = a;
		 re->child = merge(a->child, b);
	 }

	 re->next = NULL;

	 return re;
 }

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next == NULL) return head;

	return merge(head, flattenLinkedList(head->next));
}
