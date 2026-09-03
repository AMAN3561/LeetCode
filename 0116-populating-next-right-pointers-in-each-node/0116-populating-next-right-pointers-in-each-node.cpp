/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* root, int level, vector<Node*>& ans){
      if(root == NULL) return;
      
      if(level == ans.size()){
        ans.push_back(root);
      }
      else{
        root->next = ans[level];
        ans[level] = root;
      }
      solve(root->right, level + 1, ans);
      solve(root->left, level + 1, ans);
    }
    Node* connect(Node* root) {
        vector<Node*> ans;
        int level = 0;
        solve(root, 0, ans);
        return root;
    }
};