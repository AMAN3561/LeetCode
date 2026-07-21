/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public: // optimised approach :
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        // Case 1 : p & q are both are on the leftsubTree
        // rightSubtree ko neglect kro
        if(p->val < root->val && q->val < root->val){
            TreeNode* Leftans = lowestCommonAncestor(root->left, p, q);
            if(Leftans != NULL){
                return Leftans;
            }
        }
        // Case 2 : p & q are both are on the rightsubTree
        // leftsubTree ko neglect kro
        if(p->val > root->val && q->val > root->val){
            TreeNode* Rightans = lowestCommonAncestor(root->right, p, q);
            if(Rightans != NULL){
                return Rightans;
            }
        }
        // Case 3 : p in leftsubTree & q in RightsubTree
        // Case 4 : p in RightsubTree & q in leftsubTree
        return root; // for both case 3,4.
    }
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL){
//             return NULL;
//         }
//         if(root->val == p->val){
//             return p;
//         }
//         if(root->val == q->val){
//             return q;
//         }
//         TreeNode* leftans = lowestCommonAncestor(root->left, p, q);
//         TreeNode* rightans = lowestCommonAncestor(root->right, p, q);
        
//         if(leftans == NULL && rightans == NULL){
//             return NULL;
//         }
//         else if(leftans == NULL && rightans != NULL){
//             return rightans;
//         }
//         else if(leftans != NULL && rightans == NULL){
//             return leftans;
//         }
//         else{
//             // leftans != NULL && rightans != NULL
//             return root;
//         }
//     }
// };