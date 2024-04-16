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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        //edge case
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            temp->right = NULL;
            return temp;
        }

        //bfs traversal
        int level = 0; int count = 0;
        queue<TreeNode*>q;
        q.push(root);

        TreeNode* leftmost = NULL;
        TreeNode* rightmost = NULL;

        // while(!q.empty()){

        //     level++;

        //     int size = q.size();
            
        //     int i=0;
        //     for(; i<size; i++){

        //         TreeNode* top = q.front();
        //         q.pop();

        //         if(level == depth-1 && i==0){
        //             leftmost = top;
        //         }
        //         else if(level == depth-1 && i == size-1){
        //             rightmost = top;
        //             break;
        //         }

        //         if(top->left != NULL) q.push(top->left);
        //         if(top->right != NULL) q.push(top->right);
        //     }


        // }

        // if(leftmost != NULL && rightmost != NULL){

        //     TreeNode* first = new TreeNode(val);
        //     TreeNode* second = new TreeNode(val);

        //     TreeNode* left_next = leftmost->left;
        //     TreeNode* right_next = rightmost->right;

        //     leftmost->left = first;
        //     first->left = left_next;

        //     rightmost->right = second;
        //     second->right = right_next;
        // }

        // return root;
        while(!q.empty()) 
        {
            // since we have to add values on all of the nodes
            // present at that level, so take out the size
            int n = q.size(); 
            
            count++; // increase size
            while(n--)
            {
                TreeNode* curr = q.front(); // take out current node
                q.pop(); // pop it from queue
                
                // if we not reach till our required level
                // so we have to do nothing, simply push into queue
                if(count != depth - 1) 
                {
                    if(curr -> left) q.push(curr -> left);
                    if(curr -> right) q.push(curr -> right);
                }
                else 
                {
                    TreeNode* newNode = new TreeNode(val);
                    newNode -> left = curr -> left;
                    curr -> left = newNode;
                    TreeNode* newNode2 = new TreeNode(val);
                    newNode2 -> right = curr -> right;
                    curr -> right = newNode2;
                }
            }
        }

        return root; 
    }
};