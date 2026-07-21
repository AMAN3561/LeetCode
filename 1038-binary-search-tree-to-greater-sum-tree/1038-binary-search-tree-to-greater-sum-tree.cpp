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
    void makeInorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }
        // LNR :
        // L.
        makeInorder(root->left, inorder);
        // N.
        inorder.push_back(root->val);
        // R.
        makeInorder(root->right, inorder);
    }
    void updateTree(TreeNode* root, vector<int>& inorder, int& index){
        if(root == NULL){
            return;
        }
        // LNR :
        updateTree(root->left, inorder, index);
        root->val = inorder[index];
        index++;
        updateTree(root->right, inorder, index);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        // step 1 : store inorder.
        vector<int> inorder;
        makeInorder(root, inorder);
        int n = inorder.size();
        // step 2 : update inorder as per question.
        int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += inorder[i];
            inorder[i] = sum;
        }
        // step 3 : update tree using inorder
        int index = 0;
        updateTree(root, inorder, index);
        return root;
    }
};