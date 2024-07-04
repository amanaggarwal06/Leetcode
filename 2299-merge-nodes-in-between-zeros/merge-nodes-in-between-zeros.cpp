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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        int sum = 0;

        ListNode* temp = head->next;

        while(temp != NULL){

            if(temp->val == 0){
                ListNode* newnode = new ListNode(sum);
                tail->next = newnode;
                tail = newnode;
                sum = 0;
            }
            else{
                sum += temp->val;
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};