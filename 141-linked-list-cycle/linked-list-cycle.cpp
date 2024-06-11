/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        //edge cases
        if(head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        slow = slow->next;
        fast = fast->next;

        if(fast != NULL) fast = fast->next;

        while(fast != NULL && slow != fast){

            slow = slow->next;
            fast = fast->next;

            if(fast != NULL){
                fast = fast->next;
            }
        }

        if(fast == NULL) return false;
        return true;
    }
};