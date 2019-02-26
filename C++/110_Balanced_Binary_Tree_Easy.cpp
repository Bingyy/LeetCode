#include "lib.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  private:
    bool isBalancedTreeHelper(TreeNode *root, int &depth)
    {
        if (!root)
        {
            depth = 0;
            return true;
        }
        int left, right;

        if (isBalancedTreeHelper(root->left, left) && isBalancedTreeHelper(root->right, right) && abs(left - right) <= 1)
        {
            depth = max(left, right) + 1;
            return true;
        }
        return false;
    }

  public:
    bool isBalanced(TreeNode *root)
    {
        int depth;
        return isBalancedTreeHelper(root, depth);
    }
};