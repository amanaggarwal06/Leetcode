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

    void dfs(TreeNode* root, int &ans, string num){

        //base condition
        if(root == NULL){
            return;
        }
        else if(root->left == NULL && root->right == NULL){

            num.append(to_string(root->val));
            int temp = stoi(num);
            ans += temp;
            return;
        }

        num.append(to_string(root->val));
        dfs(root->left, ans, num);
        dfs(root->right, ans, num);
    }
public:
    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        // edge cases

        if(root == NULL) return 0;
        else if(root->left == NULL && root->right == NULL){
            return root->val;
        }

        string temp = "";
        dfs(root, ans, temp);
        return ans;
    }
};