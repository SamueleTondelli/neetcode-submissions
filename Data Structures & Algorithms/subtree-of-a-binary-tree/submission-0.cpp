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
        if (!p && !q) {
            return true;
        } else if ((!p && q) || (p && !q)) {
            return false;
        }

        return p->val == q->val && eq(p->left, q->left) && eq(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::vector<TreeNode*> prev, next;
        prev.push_back(root);
        while (prev.size() > 0) {
            for (TreeNode* n: prev) {
                if (eq(n, subRoot)) return true;
                if (n->left) next.push_back(n->left);
                if (n->right) next.push_back(n->right);
            }
            prev = next;
            next.clear();
        }

        return false;
    }
};
