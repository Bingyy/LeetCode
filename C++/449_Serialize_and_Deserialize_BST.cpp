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
class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string order;
        inorderDFS(root, order);
        return order;
    }

    // 内联函数
    inline void inorderDFS(TreeNode *root, string &order)
    {
        if (!root)
            return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); // burn int into 4 chars
        for (int i = 0; i < 4; i++)
        {
            order.push_back(buf[i]);
        }

        inorderDFS(root->left, order);
        inorderDFS(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // string data ==> integer data
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }

    inline TreeNode *reconstruct(const string &buffer, int &pos, int minValue, int maxValue)
    {
        if (pos >= buffer.size())
            return NULL;
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue)
            return NULL;
        TreeNode *node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));