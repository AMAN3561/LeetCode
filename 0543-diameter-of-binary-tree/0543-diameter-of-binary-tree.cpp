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
    int maxdia = 0;
    int maxDepth(TreeNode* root) {
        // base case :
        if(root == NULL){
            return 0;
        }
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);
        maxdia = max(maxdia, leftheight + rightheight);
        int ans = max(leftheight, rightheight);
        return ans+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxdia;
    }
};