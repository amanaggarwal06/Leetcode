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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        //edge cases
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rev = false;

        while(!q.empty()){

            int size = q.size();
            vector<int> v(size, 0);

            for(int i=0; i<size; i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                int indx = i;
                if(rev){
                    indx = size-1-i;
                }
                v[indx] = node->val;
            }

            ans.push_back(v);
            rev = !rev;
            
        }

        return ans;
    }
};