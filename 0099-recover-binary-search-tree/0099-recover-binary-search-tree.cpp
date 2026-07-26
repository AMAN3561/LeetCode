/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public: // use morris traversal intead of recursion.
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void Inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        // LNR :
        // L :
        Inorder(root->left);
        // N :
        //.. violationg nodes detection :
        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                first = prev; // first violating node
            }
            second = root; // second violation node
        }
        prev = root;
        // R :
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        Inorder(root);

        // at this point i'll having both violating nodes , just swap them
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

// class Solution {
// public:
//     void solve(TreeNode* root, vector<int>& inorder) {
//         if (root == nullptr)
//             return;
//         // LNR :
//         // L :
//         solve(root->left, inorder);
//         // N :
//         inorder.push_back(root->val);
//         // R :
//         solve(root->right, inorder);
//     }
//     void buldTree(TreeNode* root, vector<int>& inorder, int& index) {
//         if (root == nullptr) {
//             return;
//         }
//         buldTree(root->left, inorder, index);
//         root->val = inorder[index];
//         index++;
//         buldTree(root->right, inorder, index);
//     }
//     void recoverTree(TreeNode* root) {
//         vector<int> inorder;
//         int index = 0;
//         solve(root, inorder);
//         // sort(inorder.begin(), inorder.end());
//         int first = -1;
//         int second = -1;
//         for (int i = 0; i < inorder.size() - 1; i++) {
//             if (inorder[i] > inorder[i + 1]) {
//                 if (first == -1) {
//                     first = i;
//                 }
//                 second = i + 1;
//             }
//         }
//         swap(inorder[first], inorder[second]);
//         buldTree(root, inorder, index);
//     }
// };