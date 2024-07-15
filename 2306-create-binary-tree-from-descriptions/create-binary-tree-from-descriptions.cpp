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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {

        unordered_map<TreeNode*, TreeNode*> parentMap; 
        unordered_map<int, TreeNode*> m;

        for (auto &v : des) {

            int p = v[0], c = v[1], isLeft = v[2];
            auto parent = m.count(p) ? m[p] : (m[p] = new TreeNode(p));
            auto child = m.count(c) ? m[c] : (m[c] = new TreeNode(c));

            if (isLeft) parent->left = child;
            else parent->right = child;

            parentMap[child] = parent;
        }

        //randomly utha liya node ek------> idhr
        auto root = m.begin()->second; 

        //traverse till the root node------->
        while (parentMap.count(root)) root = parentMap[root];
        return root;
    }
};