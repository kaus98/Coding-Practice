/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int Counter = 0;
    
    ListNode* removeNthFromEnd2(ListNode* head, int n, int k) {
        Counter++;
        if (head->next == NULL){
            return NULL;
        }

        removeNthFromEnd2(head->next, n, k+1);
        if((Counter == n) && (k == 0)){
            return head->next;
            // head = head->next;
            // return head;
        }
        if((Counter - k) == n+1){
            if(head->next != NULL && head->next->next != NULL){
                head->next = head->next->next;
            }
            else if(head->next->next == NULL) {
                head->next = NULL;
            }
            // cout<<"Removing element : "<< head->val<<" Counter and K : "<<Counter<<" "<<k<<endl; 
        }
        // else{
        //     // cout<<"Other Element : "<<head->val<<" Counter and K : "<<Counter<<" "<<k<<endl;
        // }

        return head;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = removeNthFromEnd2(head, n, 0);
        return p;
    }
};
