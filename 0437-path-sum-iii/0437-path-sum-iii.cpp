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

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
*/

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] =
            1; // Initialize to handle paths that start from the root
        return dfs(root, 0LL, targetSum, prefixSums);
    }

private:
    int dfs(TreeNode* node, long long currentSum, int targetSum,
            unordered_map<long long, int>& prefixSums) {
        if (!node)
            return 0;

        currentSum += node->val;
        int numPaths = prefixSums[currentSum - targetSum];
        prefixSums[currentSum]++;

        numPaths += dfs(node->left, currentSum, targetSum, prefixSums);
        numPaths += dfs(node->right, currentSum, targetSum, prefixSums);

        prefixSums[currentSum]--; // Backtrack

        return numPaths;
    }
};

////....   O(n)
// class Solution {
// public:
//     long long total = 0;
//     void path(TreeNode* root, int targetSum, long long sum,
//     unordered_map<long long, int>& mp){
//         if (root == nullptr)
//             return;
//         sum += root->val;
//         if (mp.count(sum - targetSum))
//             total += mp[sum - targetSum];
//         mp[sum]++;
//         path(root->left, targetSum, sum, mp);
//         path(root->right, targetSum, sum, mp);
//         mp[sum]--;
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//         if (root == nullptr)
//             return 0;
//         unordered_map<long long, int> mp;
//         mp[0] = 1;
//         path(root, targetSum, 0, mp);
//         return total;
//     }
// };
///...   O(n^2)
// class Solution {
// public:
//     long long total = 0;
//     void path(TreeNode* root, int targetSum, long long sum){
//         if(root == NULL){
//             return ;
//         }
//         sum += root->val;
//         if(sum == targetSum){
//             total++;
//         }
//         path(root->left, targetSum, sum);
//         path(root->right, targetSum, sum);
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//         long long sum = 0;
//         if(root == NULL) return 0;
//         path(root, targetSum, sum);
//         pathSum(root->left, targetSum);
//         pathSum(root->right, targetSum);
//         return total;
//     }
// };