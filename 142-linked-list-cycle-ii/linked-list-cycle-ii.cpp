/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    ListNode* cycleExist(ListNode* temp){
        //edge case
        if(temp == NULL || temp->next == NULL){
            return NULL;
        }


        ListNode* slow = temp;
        ListNode* fast = temp;

        slow = slow->next;
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
        }

        while(fast != NULL && slow != fast){
            slow = slow->next;
            fast = fast->next;

            if(fast != NULL){
                fast = fast->next;
            }
        }

        if(fast == NULL) return NULL;
        return fast;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        
        //detect cycle
        //then return the starting node

        ListNode* cycle = cycleExist(head);
        if(cycle == NULL) return NULL;

        ListNode* start = head;

        while(start != cycle){
            start = start->next;
            cycle = cycle->next;
        }

        return start;

    }
};