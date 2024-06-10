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

    ListNode* merge(ListNode* head1, ListNode* head2){

        ListNode* temp = head1;

        while(temp != NULL && head2 != NULL){

            if(head2->val >= temp->val ){

                if(temp->next == NULL ||  head2->val <= temp->next->val){
                    ListNode* fwd = temp->next;
                    ListNode* sec_fwd = head2->next;

                    temp->next = head2;
                    head2->next = fwd;
                    head2 = sec_fwd;
                }

            }
            temp = temp->next;

        }
        return head1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        //edge case
        if(head1 == NULL) return head2;
        else if(head2 == NULL) return head1;

        //merge them

        if(head1->val <= head2->val){
            return merge(list1, list2);
        }
            
        return merge(list2, list1);
        
    }
};