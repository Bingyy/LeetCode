#include "lib.h"
using namespace std;

class Solution {
public:
    void helper(TreeNode* root) {
        stack<TreeNode*> treeStack;
        while (!treeStack.empty() || root != NULL) {
            while (root) {
                // 一路向左
                treeStack.push(root);
                root = root->left;
            }
            // 此时root已经为空，指向最左边的外边缘
            // 是时候取出来访问了：取出--访问--弹出三位一体
            root = treeStack.top();
            res.push_back(root->val);
            treeStack.pop();

            // 向右
            root = root->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
private:
    vector<int> res;
}

