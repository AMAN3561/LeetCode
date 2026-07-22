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
 class Info{
public:
    int minval;
    int maxval;
    int sum;
    bool isBST;
 };
class Solution {
public:
    Info solve(TreeNode* root, int& sum){
        if(root == nullptr){
            Info temp;
            temp.minval = INT_MAX;
            temp.maxval = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            return temp;
        }
        // LRN :
        Info leftans = solve(root->left, sum);
        Info rightans = solve(root->right, sum);

        // N
        Info currentAns;
        currentAns.minval = min(root->val, min(leftans.minval, rightans.minval));
        currentAns.maxval = max(root->val, max(leftans.maxval, rightans.maxval));

        currentAns.sum = root->val + leftans.sum + rightans.sum;

        // currentAns.isBST = false;
        // check whether its true or not
        if(root->val > leftans.maxval && root->val < rightans.minval && leftans.isBST && rightans.isBST){
            currentAns.isBST = true;
            /// aagar yeah ek valid BST bn gya hai toh mai sum ko update krna hai.
            sum = max(sum, currentAns.sum);
        }
        else{
            currentAns.isBST = false;
        }
        return currentAns;
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        Info ans = solve(root, sum);
        return sum;
    }
};