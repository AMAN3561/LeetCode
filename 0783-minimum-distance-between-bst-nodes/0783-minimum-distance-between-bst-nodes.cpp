class Solution {
public:
    void solve(TreeNode* root, TreeNode*& prev, int& ans){
        if(root == nullptr) return ;
        // L :
        solve(root->left, prev, ans);
        // N :
        if(prev != nullptr){ // taking the TreeNode* prev to check for difference or other like in LC-99, it is an imp approach.
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        // R :
        solve(root->right, prev, ans);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int ans = INT_MAX;
        solve(root, prev, ans);
        return ans;
    }
};