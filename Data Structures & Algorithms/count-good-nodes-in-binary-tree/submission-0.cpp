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
    void rec(TreeNode* n, int curr_max, int& good_nodes) {
        if (!n) return;

        if (n->val >= curr_max) {
            good_nodes++;
            curr_max = n->val;
        }
        rec(n->left, curr_max, good_nodes);
        rec(n->right, curr_max, good_nodes);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int good_nodes = 0;
        rec(root, root->val, good_nodes);
        return good_nodes;
    }
};
