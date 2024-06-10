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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //brute--> 1. Get total cnt of nodes in SLL;
        //         2. Now Del--> (total-N+1)th node from the start.

        //optimal--> using slow and fast pointers

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(n--){
            fast = fast->next;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow->next == head){
            slow->next = slow->next->next;
            delete head;
        }
        else{
            ListNode* temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
        }

         return dummy->next;



    }
};