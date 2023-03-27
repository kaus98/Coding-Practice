class Solution {
public:
    // ListNode* merge(ListNode* list1, ListNode* list2, ListNode* result){
    //     if(list1 != NULL && list2 != NULL){
    //         if(list1->val < list2->val){
    //             result
    //         }
    //     }
    // }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* result = &dummy;

        while(list1 != NULL && list2 != NULL){
            if(list1->val > list2->val){
                cout<<"Setting the Value from list2 : "<<list2->val<<endl;
                result->next = list2;
                list2 = list2->next;
            }
            else{
                cout<<"Setting the Value from list1 : "<<list1->val<<endl;
                result->next = list1;
                list1 = list1->next;
            }
            result = result->next;
        }

        while(list1 != NULL){
            cout<<"Emptying the List1 : "<<list1->val<<endl;
            result->next = list1;
            list1 = list1->next;
            result = result->next;
        }
        while(list2 != NULL){
            cout<<"Emptying the List2 : "<<list2->val<<endl;
            result->next = list2;
            list2 = list2->next;
            result = result->next;
        }
        return dummy.next;
    }
};
