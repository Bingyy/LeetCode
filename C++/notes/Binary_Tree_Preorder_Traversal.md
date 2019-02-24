Time: 20190224

本题对应的是LeetCode 144，Medium难度（迭代算法的难度）。

### 树的前序遍历

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

```bash
Input: [1,null,2,3]
   1
    \
     2
    /
   3
```

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?

给定一棵二叉树，输出它的前序遍历。

用递归的写法非常简单，能否用迭代的思路解决这个问题？

### 题解与思路分析

虽然递归的解法很简单，还是先从这里出发。

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* root) {
        if (!root) {
            return;
        }
        res.push_back(root->val); // 访问根元素
        helper(root->left);
        helper(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
private:
    vector<int> res;
}
```

仔细读一下这个代码，实际上是可以在脑海里模拟运行一下，然后得出迭代的版本的。

而前序遍历的迭代写法，相比于中序，后序要更简单。

根 -- 左子树 -- 右子树

将子树看做一个整体，并用栈来模拟递归的过程，先把根结点加载到栈中来，然后用一个`while`循环，直到栈空为止。栈是后入先出，所以先将右孩子结点压栈，再压左孩子结点，当然前提是存在。

```cpp
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
```

END.

