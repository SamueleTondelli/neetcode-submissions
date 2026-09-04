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
    TreeNode* lr(TreeNode* n, TreeNode* l, TreeNode* h) {
        if (l->val <= n->val && n->val <= h->val) {
            return n;
        } else if (n->val < l->val) {
            return lr(n->right, l, h);
        } else {
            return lr(n->left, l, h);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val) {
            return lr(root, p, q);
        } else {
            return lr(root, q, p);
        }
    }
};
