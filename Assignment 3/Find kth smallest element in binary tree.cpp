#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"


/*
// Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
*/
//inorder --> LNR
int ans=0,i=0;
void helper(TreeNode* root,int k)
{
    if(root == NULL)return;
    helper(root->left,k);
    i++;
    if(k == i)
    {
        ans = root->val;
        return;
    }
    helper(root->right,k);

}
int kthSmallestElementInABst(TreeNode* root, int k) {
    helper(root,k);
    return ans;
}