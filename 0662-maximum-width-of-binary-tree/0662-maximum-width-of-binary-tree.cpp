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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        int maxWidth = 0;
        q.push({root, 1}); // {root, index}
        while(!q.empty()){
            int size = q.size();
            auto leftmost = q.front().second;
            auto rightmost = q.back().second;

            maxWidth = max(maxWidth, (int)(rightmost - leftmost + 1));
            for(int i = 0; i<size; i++){
                auto front = q.front();
                q.pop();
                auto current = front.first;
                auto idx = front.second;
                if(current->left) q.push({current->left, 2 * idx});
                if(current->right) q.push({current->right, 2 * idx + 1});
            }
        }
        return maxWidth;
    }
};