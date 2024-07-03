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

    int solve(TreeNode* root){

        //base case
        if(root == NULL){
            return 0;
        }

        int lh = solve(root->left);
        int rh = solve(root->right);

        if(abs(lh-rh) > 1) return -1;

        if(lh == -1 || rh == -1){
            return -1;
        }

        return (1+ max(lh,rh));
    }
public:
    bool isBalanced(TreeNode* root) {
        
        int val = solve(root);

        if(val == -1) return false;
        return true;
    }
};