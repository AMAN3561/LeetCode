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
    int leftheight(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }
    int rightheight(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = leftheight(root);
        int rh = rightheight(root);

        if(lh == rh){
            // FCBT :
            return (1 << lh) - 1;
        }
        // lh != rh :
        int countleft = countNodes(root->left);
        int countright = countNodes(root->right);
        return countleft + countright + 1;
    }
};


// class Solution {
// public:
//     int count = 0;
//     void inorder(TreeNode* root){
//         if(root == nullptr) return;

//         // LNR :
//         // L :
//         inorder(root->left);
//         // N :
//         count++;
//         // R :
//         inorder(root->right);
//     }
//     int countNodes(TreeNode* root) {
//         inorder(root);
//         return count;
//     }
// };