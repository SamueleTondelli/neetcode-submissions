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
    void rec(TreeNode* n, queue<int>& q) {
        if (!n) return;
        rec(n->left, q);
        q.push(n->val);
        rec(n->right, q);
    }

    int kthSmallest(TreeNode* root, int k) {
        queue<int> q;
        rec(root, q);
        for (int i = 1; i < k; i++) {
            q.pop();
        }
        return q.front();
    }
};
