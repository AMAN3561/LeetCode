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
    void Ino(TreeNode* root, vector<int>& arr){
        if(root == nullptr) return ;

        Ino(root->left, arr);
        arr.push_back(root->val);
        Ino(root->right, arr);
    }
    int getMinimumDifference(TreeNode* root) {
        int difference = INT_MAX;
        vector<int> arr;
        Ino(root, arr);
        for(int i = 1; i<arr.size(); i++){
            difference = min(difference, arr[i] - arr[i - 1]);
        }
        return difference;
    }
};