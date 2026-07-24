class Solution {
public:
    unordered_map<int, int>postorderMp;
    TreeNode* build(vector<int>& preorder, int preorderleftidx, int preorderrightidx, vector<int>& postorder, int postorderleftidx, int postorderrightidx){
        if(preorderleftidx > preorderrightidx) return nullptr;
       
        // main logic :
        // first preorder element would be root .
        TreeNode* root = new TreeNode(preorder[preorderleftidx]);

        if(preorderleftidx == preorderrightidx) return root;

        // next preorder element in the left child root 
        int leftrootval = preorder[preorderleftidx + 1];

        //  find it in the postorder to get the leftsubtree size
        int index = postorderMp[leftrootval];
        int leftsize = index - postorderleftidx + 1;

        root->left = build(preorder, preorderleftidx + 1, preorderleftidx + leftsize, postorder, postorderleftidx, index);
        root->right = build(preorder, preorderleftidx + leftsize + 1, preorderrightidx, postorder, index + 1, postorderrightidx - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i<postorder.size(); i++){
            postorderMp[postorder[i]] = i;
        }
        int n = preorder.size();
        int preorderleftidx = 0;
        int preorderrightidx = n - 1;
        int postorderleftidx = 0;
        int postorderrightidx = n - 1;
        TreeNode* root = build(preorder, preorderleftidx, preorderrightidx, postorder, postorderleftidx, postorderrightidx);
        return root;
    }
};