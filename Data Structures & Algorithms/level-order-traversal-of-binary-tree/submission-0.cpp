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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (!root) return levels;
        
        vector<TreeNode*> next, prev;
        prev.push_back(root);
        while (!prev.empty()) {
            vector<int> l;
            for (TreeNode* n: prev) {
                l.push_back(n->val);
                if (n->left) next.push_back(n->left);
                if (n->right) next.push_back(n->right);
            }

            levels.push_back(l);
            prev = next;
            next.clear();
        }

        return levels;
    }
};
