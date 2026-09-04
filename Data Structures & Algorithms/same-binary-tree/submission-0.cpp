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
    bool eq(TreeNode* p, TreeNode* q) {
        if (!q && !p) {
            return true;
        } else if ((!q && p) || (q && !p)) {
            return false;
        }

        return eq(p->left, q->left) && eq(p->right, q->right) && p->val == q->val;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return eq(p, q);
    }
};
