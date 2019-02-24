这是用空间换时间的做法，就是具体算法调用了108的折半查找。所以需要先把链表元素存储到数组，这是一次O(n)遍历，同时，也额外占用O(n)的空间，并不是很好的方法，先验证一下这个做法是否可AC，答案是可行，记录一下Baseline。

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 样例的写法是每次寻找当前的根元素相对靠右，一般我们折半查找相对靠左
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_h(nums,0, nums.size() - 1);  
        
    }
    
    TreeNode* sortedArrayToBST_h(vector<int>& nums, int l, int r) {
        
        int low = l, high = r;
        TreeNode* root = nullptr;
        
        if (l <= r) { // 这个判定条件很重要
            int mid = low + ( high - low ) / 2;
            root = new TreeNode(nums[mid]);

            root->left = sortedArrayToBST_h(nums, low, mid - 1); // 左子树
            root->right = sortedArrayToBST_h(nums, mid + 1, high); // 右子树
        }  
        
        return root;
    }
};
```
