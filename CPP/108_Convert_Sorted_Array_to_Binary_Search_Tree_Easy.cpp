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
