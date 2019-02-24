#include "lib.h"
using namespace std;

class Solution {
public:
    void helper(TreeNode* root) {
        if (!root) {
            return;
        }
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode* temp = treeStack.top();
            res.push_back(temp->val);
            treeStack.pop(); // 访问完即弹出
            if (temp->right) {
                treeStack.push(temp->right);
            } 
            if (temp->left) {
                treeStack.push(temp->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
private:
    vector<int> res;
}
