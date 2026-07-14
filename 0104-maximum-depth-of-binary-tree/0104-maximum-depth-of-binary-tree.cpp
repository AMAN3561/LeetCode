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
    int maxDepth(TreeNode* root) {
        // base case :
        if(root == NULL){
            return 0;
        }
        int leftheight = maxDepth(root->left) + 1;
        int rightheight = maxDepth(root->right) + 1;

        int ans = max(leftheight, rightheight);
        return ans;
    }
};






// if(root == NULL){
//             return 0;
//         }
//         int count = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         // using null as a marker.
//         q.push(NULL);
//         while(!q.empty()){
//             TreeNode* front = q.front();
//             q.pop();
//             if(front == NULL){
//                 // current level ke saare value print ho chuki hai 
//                 cout<<endl;
//                 // aagar q empty h, then dont insert NULL
//                 // aagar inseert hua toh infinite loop mai chale gyenge.
//                 if(!q.empty()){
//                     q.push(NULL);
//                 }
//                 count++;
//             }
//             else{
//                 cout<< front->val <<" ";

//                 if(front->left != NULL){
//                     q.push(front->left);
//                 }
//                 if(front->right != NULL){
//                     q.push(front->right);
//                 }
//             }
//         }
//         return count;