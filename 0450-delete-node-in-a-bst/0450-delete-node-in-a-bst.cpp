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
    int getmax(TreeNode* root){
        if(root == NULL){
            return -1;
        }
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            // deletion phase ->
            // 4 case :
            //delete node.
            // 1 case - 0 child -> leaf node
            if(root->left == NULL && root->right == NULL){
                TreeNode* temp = root;
                delete temp;
                return NULL;
            }
            // 1 case - 1 child -> left
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root;
                TreeNode* child = root->left;
                temp->left = NULL;
                delete temp;
                return child;
            }
            // 1 case - 1 child -> right
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root;
                TreeNode* child = root->right;
                temp->right = NULL;
                delete temp;
                return child;
            }
            // 1 case - 2 child  :
            if(root->left != NULL && root->right != NULL){
                // 2 choices ->
                // 1 : Replace node with max value in Left subTree & delete Max value.
                // 2:  Replace node with Min value in RightSubTree & delete Min value.

                // logic :
                // first we will replace the node to delete with the max value in its leftsubtree
                // after that we will call the delete function on LST for the replaced value.
                // 1 step : replacement.
                int replaceValue = getmax(root->left);
                root->val = replaceValue;
                /// 2nd step : deletion
                root->left = deleteNode(root->left, replaceValue);
                return root;
            }
        }
        else{
            // searching phase ->
            // not match :
            if(key > root->val){
                // deletion right side mai hoga 
                root->right = deleteNode(root->right, key);
            }
            else{
                // deletion left side mai hoga 
                root->left = deleteNode(root->left, key);
            }
        }
        return root;
    }
};