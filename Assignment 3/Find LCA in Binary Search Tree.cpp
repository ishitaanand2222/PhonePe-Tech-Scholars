#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"

/*
Definition for TreeNode
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
}

Use new TreeNode(data) to create new Node
*/

TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == NULL)
    return NULL;

    if(p->val < root->val and q->val < root->val)
    {
        helper(root->left,p,q);
    }
    else if(q->val > root->val and p->val > root->val)
    {
        helper(root->right,p,q);
    }
    else
    return root;
}
TreeNode* lowestCommonAncestorInBST(TreeNode *root, TreeNode *p, TreeNode *q) {
    return helper(root,p,q);
}