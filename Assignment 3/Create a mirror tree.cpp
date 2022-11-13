#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"
/*
Definition of TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {}

    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
*/
void helper(TreeNode* root)
{
    if(root == NULL)
    return;

    if(root->left and root->right)
    {
        swap(root->left,root->right);
    }
    else if(root->left)
    {
        root->right = root->left;
        root->left = NULL;
    }
    else if(root->right)
    {
        root->left = root->right;
        root->right = NULL;
    }
    helper(root->left);
    helper(root->right);

    return;
}
TreeNode* mirrorBinaryTree(TreeNode* root) {
    helper(root);
    return root;
}
