class FindElements {
public:
    unordered_set<int> st;
    void Dfs(TreeNode* root, int x){
        if(root == nullptr){
            return;
        }
        root->val = x;
        st.insert(x);
        Dfs(root->left, 2*x + 1);
        Dfs(root->right, 2*x + 2);
    }
    FindElements(TreeNode* root) {
        st.clear();
        Dfs(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};