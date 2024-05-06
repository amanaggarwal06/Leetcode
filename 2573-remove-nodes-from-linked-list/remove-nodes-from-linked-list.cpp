// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
        
//         //edge case
//         if(head == NULL || head->next == NULL){
//             return head;
//         }

//         int maxi = head->val;

//         ListNode* temp = head->next;
//         ListNode* prev = head;
//         ListNode* newhead = NULL; ListNode* tail = newhead;

//         while(temp != NULL){
            
//             if(temp->val > maxi){
//                 //remove it

//                 //insert node in the ans LL
//                 ListNode* node = new ListNode(temp->val);
//                 if(newhead == NULL){
//                     newhead = node;
//                     tail = newhead;
//                 }
//                 else{
//                     tail->next = node;
//                     tail = node;
//                 }
//                 prev->next = temp->next;
//             }
//             else{
//                 prev = temp;
//             }
            
//             temp = temp->next;
//         }

//         if(newhead == NULL) return head;
//         return newhead;
//     }
// };
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != nullptr) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
    }
};