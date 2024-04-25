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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;

        while(temp != NULL){

            bool flag = false;
            while(temp->next != NULL && temp->val == temp->next->val){
                temp->next = temp->next->next;
                flag = true;
            }

            if(flag){
                //temp is my repetetive node
                if(prev != NULL){
                    prev->next = temp->next;
                }
                else{
                    //head node
                    head = temp->next;
                }
            }
            else{
                prev = temp;
            }

            temp = temp->next;
        }

        return head;
    }
};