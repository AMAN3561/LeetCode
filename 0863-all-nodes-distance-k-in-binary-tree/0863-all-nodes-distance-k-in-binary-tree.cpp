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
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void InorderTraversal(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left != NULL){
            parent[root->left] = root;
        }
        InorderTraversal(root->left);

        if(root->right != NULL){
            parent[root->right] = root;
        }
        InorderTraversal(root->right);
    }
    void BfsTraversal(TreeNode* target, int k, vector<int>& result){
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();
            if(k == 0){
                break;
            }
            while(n--){
                TreeNode* current = q.front();
                q.pop();
                // LEft : 
                if(current->left != nullptr && !visited.count(current->left->val)){
                    q.push(current->left);
                    visited.insert(current->left->val);
                }
                //RIght :
                if(current->right != nullptr && !visited.count(current->right->val)){
                    q.push(current->right);
                    visited.insert(current->right->val);
                }

                if(parent.count(current) && !visited.count(parent[current]->val)){
                    q.push(parent[current]);
                    visited.insert(parent[current]->val);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result; 
        InorderTraversal(root);
        BfsTraversal(target, k, result);
        return result;
    }
};