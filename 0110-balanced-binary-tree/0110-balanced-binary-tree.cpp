/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg$0*left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxdepth(TreeNode* root){
        if(root == NULL) return 0;
        int leftH = maxdepth(root->left) + 1;
        int rightH = maxdepth(root->right) + 1;
        int ans = max(leftH, rightH);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int leftH = maxdepth(root->left);
        int rightH = maxdepth(root->right);
        int ans = abs(leftH - rightH);
        return abs(leftH - rightH) <= 1 &&
                isBalanced(root->left) &&
                isBalanced(root->right);
    }
};