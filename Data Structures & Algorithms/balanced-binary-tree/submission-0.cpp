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
    int height(TreeNode* root, bool& balanced) {
        if (!root) {
            return 0;
        }

        int l_h = height(root->left, balanced);
        int r_h = height(root->right, balanced);
        if (abs(r_h - l_h) > 1) {
            balanced = false;
        }

        return max(r_h, l_h) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
};
