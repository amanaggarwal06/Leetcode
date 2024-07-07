/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){

            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                //get the right-most node of left-subtree
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    //thread doesn't exit
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    //thread exit
                    ans.push_back(curr->val);
                    prev->right = NULL; //thread deletion
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};