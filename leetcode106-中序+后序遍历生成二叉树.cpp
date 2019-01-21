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
    
    // 根据中序和后序遍历序列构建二叉树
    // 可以唯一构建一棵二叉树
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       return  helper(inorder, 0, inorder.size(), postorder, 0, postorder.size()); // 左闭右   
    }
    
    // i,j是中序遍历序列的[i,j),j可以看成是中序序列的元素个数
    // 传递的是引用变量，所以需要用下标跟踪
    TreeNode* helper(vector<int>& inorder, int inL, int inR, vector<int>& postorder, int pL, int pR) {
        
        if(inL >= inR || pL >= pR) {
            return NULL;
        }
            
        int root = postorder[pR-1];
        TreeNode* rootNode = new TreeNode(root);
        
        int k; // 根元素在中序序列的位置
        for (int i = inL;i < inR; i++) {
            if (inorder[i] == root) {
                k = i;
                break;
            }        
        }
        
        int leftTreeSize = k - inL; // 不含k下标
        
        // 划分左右子树
        rootNode->left = helper(inorder, inL, inL + leftTreeSize, postorder, pL, pL + leftTreeSize);
        
        rootNode->right = helper(inorder, inL + leftTreeSize + 1, inR, postorder, pL + leftTreeSize, pR - 1);
        
        
        return rootNode;
    }
};
