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
class BSTiterator{
    stack <TreeNode*> st;
    bool rev = false;
    
public:
    BSTiterator(TreeNode* temp, bool reverse){
        rev = reverse;
        pushall(temp);
    }

    void pushall(TreeNode* node){

        if(rev){

            //right->root->left
            while(node != NULL){
                st.push(node);
                node = node->right;
            }
        }
        else{

            while(node != NULL){
                st.push(node);
                node = node->left;
            }
        }
    }

    int next(){

        // if(hasNext() == false){
        //     return -1;
        // }

        TreeNode* topi = st.top();
        st.pop();

        if(rev){
            pushall(topi->left);
        }
        else{
            pushall(topi->right);
        }

        return topi->val;
    }

    bool hasNext(){

        return (!st.empty());
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTiterator obj1(root, false), obj2(root, true);

        int first = obj1.next(), last = obj2.next();

        while(first < last){

            int sum = first + last;

            if(sum == k) return true;
            else if(sum > k){
                
                if(obj2.hasNext()){
                    last = obj2.next();
                }
                else{
                    return false;
                }
            }
            else{
                if(obj1.hasNext()){
                    first = obj1.next();
                }
                else{
                    return false;
                }
            }
        }

        return false;
    }
};