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
    void helper(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        stack<TreeNode *> treeStack;
        treeStack.push(root);

        while (!treeStack.empty())
        {
            TreeNode *temp = treeStack.top();
            res.push_back(temp->val);
            treeStack.pop();
            // 和前序遍历相反，先左后右
            if (temp->left)
            {
                treeStack.push(temp->left);
            }
            if (temp->right)
            {
                treeStack.push(temp->right);
            }
        }
        // 翻转即为正确结果
        reverse(res.begin(), res.end());
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        helper(root);
        return res;
    }

  private:
    vector<int> res;
};

// https://www.cnblogs.com/fang92/p/4782729.html