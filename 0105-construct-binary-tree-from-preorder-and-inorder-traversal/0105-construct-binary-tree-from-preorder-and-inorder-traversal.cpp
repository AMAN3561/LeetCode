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
    int getIndex(int element, vector<int> arr){
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preorderindex, int inorderstart, int inorderend){
        if(preorderindex >= preorder.size()){
            return NULL;
        }
        if(inorderstart > inorderend){
            return NULL;
        } 
        // main logic :
        int element = preorder[preorderindex];
        preorderindex++;
        //... creating the tree:
        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder = getIndex(element, inorder);

        root->left = build(preorder, inorder, preorderindex, inorderstart, elementIndexInsideInorder -1);
        root->right = build(preorder, inorder, preorderindex, elementIndexInsideInorder + 1, inorderend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0;
        int inorderstart = 0;
        int inorderend = inorder.size()-1;
        TreeNode* root = build(preorder, inorder, preorderindex, inorderstart, inorderend);
        return root;
    }
};