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
    bool isPalindrome(ListNode* head) {
        
        //edge case
        if(head == NULL || head->next == NULL){
            return true;
        }

        // //make a reversed linkedlist and then compare it with the originak linkedlist which is given.

        ListNode* head2 = head;
        ListNode* prev = NULL;

        while(head2 != NULL){

            int data = head2->val;
            ListNode* temp = new ListNode(data);
            temp->next = prev;
            prev = temp;
            head2 = head2->next;
        }

        while(head != NULL && prev != NULL){

            if(head->val == prev->val){
                head = head->next;
                prev = prev->next;
            }
            else{
                return false;
            }
        }

        return true;

        //---------------------------------------------
        // stack<int> st;
        // ListNode* temp = head;

        // while(temp != NULL){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;

        // while(temp != NULL && !st.empty()){

        //     if(temp->val != st.top()){
        //         return false;
        //     }

        //     temp = temp->next;
        //     st.pop();

        // }

        return true;
    }
};