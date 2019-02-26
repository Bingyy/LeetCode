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
  public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        return traverse(s, t);
    }
    // 判断两个子树是否相等
    bool equals(TreeNode *x, TreeNode *y)
    {
        if (!x && !y)
        {
            return true;
        }
        if (!x || !y)
        {
            return false;
        }
        if (x->val == y->val)
        {
            return equals(x->left, y->left) && equals(x->right, y->right);
        }
        return false;
    }

    bool traverse(TreeNode *s, TreeNode *t)
    {
        return s && (equals(s, t) || traverse(s->left, t) || traverse(s->right, t));
    }
};