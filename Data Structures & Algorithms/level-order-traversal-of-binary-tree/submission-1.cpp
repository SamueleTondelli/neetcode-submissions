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
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int nodes = q.size();
            vector<int> l;
            for (int i = 0; i < nodes; i++) {
                TreeNode* n = q.front();
                l.push_back(n->val);
                q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            levels.push_back(l);
        }

        return levels;
    }
};
