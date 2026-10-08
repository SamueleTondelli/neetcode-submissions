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
    void rec(TreeNode* n, int& i, int k, int& res) {
        if (!n) return;
        rec(n->left, i, k, res);
        if (i == k) {
            res = n->val;
        }
        i++;
        rec(n->right, i, k, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 1, res = -1;
        rec(root, i, k, res);
        return res;
    }
};
