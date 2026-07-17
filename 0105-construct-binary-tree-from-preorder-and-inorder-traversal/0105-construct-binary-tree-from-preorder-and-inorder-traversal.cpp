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
    unordered_map<int, int> inorderMap;
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
        int elementIndexInsideInorder = inorderMap[element];

        root->left = build(preorder, inorder, preorderindex, inorderstart, elementIndexInsideInorder -1);
        root->right = build(preorder, inorder, preorderindex, elementIndexInsideInorder + 1, inorderend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        int preorderindex = 0;
        int inorderstart = 0;
        int inorderend = inorder.size()-1;
        TreeNode* root = build(preorder, inorder, preorderindex, inorderstart, inorderend);
        return root;
    }
};