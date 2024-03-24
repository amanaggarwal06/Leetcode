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
    void reorderList(ListNode* head) {

        //edge cases
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return;
        }
        
        // ListNode* head2 = head;
        // ListNode* prev = NULL; int len = 0;

        // while(head2 != NULL){

        //     ListNode* fwd = head2->next;
        //     head2->next = prev;
        //     prev = head2;
        //     head2 = fwd;
        //     len++;
        // }

        // int new_len = len/2;
        // ListNode* temp = head;

        // ListNode* curr_fwd =NULL;
        // ListNode* prev_fwd = NULL; ListNode* prev_prev = NULL;

        // while(new_len && temp!= NULL && prev != NULL){

        //     curr_fwd = temp->next;
        //     prev_fwd = prev->next;
        //     temp->next = prev;
        //     prev->next = prev_fwd;
        //     prev_prev = prev;
        //     prev = prev_fwd;
        //     temp = curr_fwd;
        //     new_len--;
        // }

        // if(len%2 == 0){
        //     prev_prev->next = NULL;
        // }
        // else{
        //     temp->next = NULL;
        // }


        stack<ListNode*> st;
        ListNode* temp = head; int len = 0;

        while(temp != NULL){

            st.push(temp);
            temp = temp->next;
            len++;
        }

        ListNode* temp2 = head;
         int new_len = len/2;
        //  ListNode* topi = head;

         while(new_len){
            
            ListNode* topi = st.top();
            st.pop();

            ListNode* fwd = temp2->next;
            temp2->next = topi;
            topi->next = fwd;
            temp2 = fwd;
            new_len--;
         }

        //  if(len%2 == 0){
        //     // topi->next == NULL;
        //     // temp2 = NULL;
        //     temp2->next == NULL;
        //  }
        //  else{
        //     temp2->next == NULL;
        //  }
        temp2->next = NULL;

        

    }
};