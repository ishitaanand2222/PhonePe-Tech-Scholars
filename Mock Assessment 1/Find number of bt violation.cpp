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

int cnt = 0;
int helper(TreeNode* root)
{
    if(root == NULL)
    return 0;

    int left = 1 + helper(root->left);
    int right = 1 + helper(root->right);

    if(abs(left-right)>1)cnt++;

    return max(left,right);

}
int findNumberOfBtVoilations(TreeNode* root) {
    int a = helper(root);
    return cnt;
}
