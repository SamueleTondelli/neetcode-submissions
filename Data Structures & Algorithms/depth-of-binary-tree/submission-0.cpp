/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void depth(TreeNode* n, int& max_depth, int curr_depth) {
        if (n == nullptr) {
            if (max_depth < curr_depth) max_depth = curr_depth;
            return;
        }

        depth(n->left, max_depth, curr_depth + 1);
        depth(n->right, max_depth, curr_depth + 1);
    }

    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        depth(root, max_depth, 0);
        return max_depth;
    }
};
