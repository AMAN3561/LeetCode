// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         queue<pair<TreeNode*, pair<int, int>>> q;
//         vector<tuple<int, int, int>> nodes;

//         q.push({root, {0,0}});
//         while(!q.empty()){
//             auto Front = q.front();
//             q.pop();
//             TreeNode* node = Front.first;
//             int x = Front.second.first;
//             int y = Front.second.second;

//             nodes.push_back({x, y, node->val});

//             if(node->left){
//                 q.push({node->left, {x-1, y + 1}});
//             }
//             if(node->right){
//                 q.push({node->right, {x + 1, y + 1}});
//             }
//         }
//         sort(nodes.begin(), nodes.end());
//         vector<vector<int>> ans;
//         int prevX = INT_MIN;

//         for(auto it: nodes){
//             int x = get<0>(it);
//             int y = get<1>(it);
//             int value = get<2>(it);

//             if(x != prevX){
//                 ans.push_back({});
//                 prevX = x;
//             }
//             ans.back().push_back(value);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    void Inorder(TreeNode* root, int x, int y, vector<tuple<int, int, int>>& nodes){
        if(root == nullptr){
            return;
        }
        // L :
        Inorder(root->left, x - 1, y + 1, nodes);
        // N:
        nodes.push_back({x, y, root->val});
        // R:
        Inorder(root->right, x + 1, y + 1, nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;

        Inorder(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int prevX = INT_MIN;
        for(auto it: nodes){
            int x = get<0>(it);
            int y = get<1>(it);
            int value = get<2>(it);

            if(x != prevX){
                ans.push_back({});
                prevX = x;
            }
            ans.back().push_back(value);
        }
        return ans;
    }
};