/*
// Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
*/
class ValidateBinarySearchTree {
public:
    bool helper(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if(!root)return true;

        if(left and root->val < left->val or right and root->val > right->val)
        return false;

        bool l = helper(root->left,left,root);
        bool r = helper(root->right,root,right);

        return l and r;
    }
    bool validateBinarySearchTree(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};