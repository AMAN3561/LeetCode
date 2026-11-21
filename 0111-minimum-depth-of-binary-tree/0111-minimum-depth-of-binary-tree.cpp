class Solution {
public:
    int minDepth(TreeNode* root) {
        // base case :
        if(root == NULL){
            return 0;
        }
        if(root->left == nullptr){
            return minDepth(root->right)+1;
        }
        if(root->right == nullptr){
            return minDepth(root->left)+1;
        }
        int leftheight = minDepth(root->left) + 1;
        int rightheight = minDepth(root->right) + 1;

        int ans = min(leftheight, rightheight);
        return ans;
    }
};