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
    bool InorderTraversal(TreeNode* root, TreeNode*& prev){
        if(root == nullptr) return true;

        // L:
        if (!InorderTraversal(root->left, prev))
            return false;
        // N :
        if (prev != nullptr && root->val <= prev->val)
            return false;

        prev = root;
        // R :
        return InorderTraversal(root->right, prev);

    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return InorderTraversal(root, prev);
    }
};


// class Solution {
// public:
//     void InorderTraversal(TreeNode* root, vector<int>& arr){
//         if(root == nullptr) return;

//         // L:
//         InorderTraversal(root->left, arr);
//         // N :
//         arr.push_back(root->val);
//         // R :
//         InorderTraversal(root->right, arr);
//     }
//     bool isValidBST(TreeNode* root) {
//         vector<int> arr;
//         InorderTraversal(root, arr);

//         for(int i = 1; i<arr.size(); i++){
//             if(arr[i] <= arr[i - 1]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };