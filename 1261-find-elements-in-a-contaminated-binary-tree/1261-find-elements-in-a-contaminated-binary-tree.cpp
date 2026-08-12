// class FindElements {
// public: // by DFS:
//     unordered_set<int> st;
//     void Dfs(TreeNode* root, int x){
//         if(root == nullptr){
//             return;
//         }
//         root->val = x;
//         st.insert(x);
//         Dfs(root->left, 2*x + 1);
//         Dfs(root->right, 2*x + 2);
//     }
//     FindElements(TreeNode* root) {
//         st.clear();
//         Dfs(root, 0);
//     }
    
//     bool find(int target) {
//         return st.count(target);
//     }
// };





class FindElements {
public: // by BFS:
    unordered_set<int> st;
    void Bfs(TreeNode* root, int x){
        queue<TreeNode*> q;
        root->val = x;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            st.insert(temp->val);

            if(temp->left != nullptr){
                temp->left->val = 2* temp->val + 1;
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                temp->right->val = 2* temp->val + 2;
                q.push(temp->right);
            }
        }
    }
    FindElements(TreeNode* root) {
        st.clear();
        Bfs(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};