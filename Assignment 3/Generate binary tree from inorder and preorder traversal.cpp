#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"


/*
// Definition of TreeNode
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
unordered_map<int,int>mp;
int idx = 0;
TreeNode* helper(int start, int end, vector<int> &preorder, vector<int> &inorder)
{
    if(start > end)
    return NULL;

    TreeNode* node = new TreeNode(preorder[idx++]);
    int j = mp[node->val];
    
    node->left = helper(start,j-1,preorder,inorder);
    node->right = helper(j+1,end,preorder,inorder);

    return node;
}
TreeNode* constructBinaryTreeFromPreorderAndInorderTraversal(vector<int> &preorder, vector<int> &inorder) {
    for(int i=0;i<inorder.size();i++)
    mp[inorder[i]]=i;

    int n = inorder.size();
    return helper(0,n-1,preorder,inorder);
}