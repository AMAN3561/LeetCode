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


// class Solution {
// public:
//     // solved using Inorder Traversal :
//     void makeInorder(TreeNode* root, vector<int>& inorder){
//         if(root == NULL){
//             return;
//         }
//         // LNR:
//         makeInorder(root->left, inorder);
//         inorder.push_back(root->val);
//         makeInorder(root->right, inorder);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> inorder;
//         makeInorder(root, inorder);
//         return inorder[k-1];
//     }
// };



class Solution {
public:
    // M-II:
    void solve(TreeNode* root, int k, int& count, TreeNode* &ans){
        if(root == NULL){
            return;
        }
        // LNR :
        // L :
        solve(root->left, k, count, ans);
        // N :
        count++;
        if(count == k){
            ans = root;
        }
        // R :
        solve(root->right, k, count, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = NULL;
        int count = 0;
        solve(root, k, count, ans);
        return ans->val;
    }
};