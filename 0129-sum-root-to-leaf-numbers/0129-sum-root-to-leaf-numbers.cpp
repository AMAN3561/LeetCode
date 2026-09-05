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
    void DFSPreorderTraversal(TreeNode* root, string path, int& ans){
        if(root == nullptr) return;
        // N
        path += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            ans += stoi(path);
        }
        // L :
        DFSPreorderTraversal(root->left, path,ans);
        // R :
        DFSPreorderTraversal(root->right, path, ans);
    }
    int sumNumbers(TreeNode* root) {
        string path = "";
        int ans = 0;
        DFSPreorderTraversal(root, path, ans);
        return ans;
    }
};