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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rv;
        if (!root) {
            return rv;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int nodes = q.size();
            rv.push_back(q.back()->val);
            for (int i = 0; i < nodes; i++) {
                TreeNode* n = q.front();
                q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }

        return rv;
    }
};
