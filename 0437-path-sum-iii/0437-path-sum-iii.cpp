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
    long long total = 0;
    void path(TreeNode* root, int targetSum, long long sum){
        if(root == NULL){
            return ;
        }
        sum += root->val;
        if(sum == targetSum){
            total++;
        }
        path(root->left, targetSum, sum);
        path(root->right, targetSum, sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long sum = 0;
        if(root == NULL) return 0;
        path(root, targetSum, sum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return total;
    }
};