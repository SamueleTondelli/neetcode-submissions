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
    pair<int, int> rec(TreeNode* n, bool& res) {
        if (!n) return pair(INT_MAX, INT_MIN);
        
        pair<int, int> mmn(n->val, n->val);
        if (n->left) {
            pair<int, int> mml = rec(n->left, res);
            res &= (mml.second < n->val);
            mmn.first = min(mmn.first, min(mml.first, mml.second));
            mmn.second = max(mmn.second, max(mml.first, mml.second));
        }
        if (n->right) {
            pair<int, int> mmr = rec(n->right, res);
            res &= (n->val < mmr.first);
            mmn.first = min(mmn.first, min(mmr.first, mmr.second));
            mmn.second = max(mmn.second, max(mmr.first, mmr.second));
        }

        return mmn;
    }

    bool isValidBST(TreeNode* root) {
        bool result = true;
        rec(root, result);
        return result;
    }
};
