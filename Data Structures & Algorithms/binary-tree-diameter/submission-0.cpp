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
    int diam(TreeNode* n, int& max_diameter) {
        if (!n) {
            return 0;
        }

        int l_h = diam(n->left, max_diameter);
        int r_h = diam(n->right, max_diameter);
        max_diameter = max(max_diameter, l_h + r_h);
        return max(l_h, r_h) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        int h = diam(root, max_diameter);
        return max_diameter;
    }
};
