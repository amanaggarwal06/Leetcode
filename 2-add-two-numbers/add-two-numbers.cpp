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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        int carry = 0;

        while(l1 != NULL || l2!= NULL || carry != 0){

            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2!= NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            int val = (sum + carry);
            carry = val/10;

            val = val%10;

            ListNode* temp2 = new ListNode(val);
            temp->next = temp2;
            temp = temp->next;

            
        }

        return head->next;
    }
};