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
    void InorderTraversal(TreeNode* root, int low, int high, int& sum){
        vector<int> arr;
        if(root == nullptr) return;
        InorderTraversal(root->left, low, high, sum);
        arr.push_back(root->val);
        InorderTraversal(root->right, low, high, sum);

        for(int i = 0; i<arr.size(); i++){
            if(arr[i] >= low && arr[i] <= high){
                sum += arr[i];
            }
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        InorderTraversal(root, low, high, sum);
        return sum;
    }
};