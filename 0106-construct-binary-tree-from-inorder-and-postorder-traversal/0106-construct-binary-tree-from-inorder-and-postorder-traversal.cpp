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
    int getIndex(int element , vector<int> arr){
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& postorderIndex, int inorderStart, int inorderEnd){
        if(postorderIndex < 0){
            return NULL;
        }
        if(inorderStart > inorderEnd){
            return NULL;
        }
        // main logic :
        int element = postorder[postorderIndex];
        postorderIndex--;

        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder = getIndex(element, inorder);
        root->right = build(inorder, postorder, postorderIndex, elementIndexInsideInorder + 1, inorderEnd);
        root->left = build(inorder, postorder, postorderIndex, inorderStart, elementIndexInsideInorder - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size() -1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        TreeNode* root = build(inorder, postorder, postorderIndex, inorderStart, inorderEnd);
        return root;
    }
};