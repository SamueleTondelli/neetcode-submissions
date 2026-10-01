/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void rec(unordered_map<int, Node*>& cloned_map, unordered_set<int>& visited, Node* node, Node* cloned) {
        if (visited.contains(node->val)) return;
        visited.insert(node->val);
        vector<Node*> neighbors;
        for (Node* n: node->neighbors) {
            if (cloned_map.contains(n->val)) {
                neighbors.push_back(cloned_map[n->val]);
            } else {
                Node* c = new Node(n->val);
                cloned_map[n->val] = c;
                neighbors.push_back(c);
            }
        }

        cloned->neighbors = neighbors;
        for (int i = 0; i < neighbors.size(); i++) {
            rec(cloned_map, visited, node->neighbors[i], neighbors[i]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> cloned_map;
        unordered_set<int> visited;
        Node* cloned = new Node(node->val);
        cloned_map[node->val] = cloned;
        rec(cloned_map, visited, node, cloned);
        return cloned;
    }

};
