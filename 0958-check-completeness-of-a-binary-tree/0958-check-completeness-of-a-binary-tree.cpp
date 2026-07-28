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
    bool isCompleteTree(TreeNode* root) {
        // level order wise traversal krenge :
        // rule :
        // if there exist an element after the null, then it is not CBT
        // if there exist no element its a CBT.
        queue<TreeNode*> q;
        q.push(root);
        bool nullfound = false;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == nullptr){
                nullfound = true;
            }
            else{
                // aagar yeah valid element se phle null mila hai toh,
                // iska mtlb CBT nhi hai
                // check kr lo 
                if(nullfound == true){
                    return false;
                }
                // mujhe ek valid element mila hai.
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};