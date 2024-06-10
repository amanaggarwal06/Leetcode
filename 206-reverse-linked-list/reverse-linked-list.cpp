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
    ListNode* reverseList(ListNode* head) {

        //edge case
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* fwd = NULL;

        while(temp != NULL){
            fwd = temp->next;
            temp->next = prev;
            prev = temp;
            temp = fwd;
        }

        return prev;
    }
};