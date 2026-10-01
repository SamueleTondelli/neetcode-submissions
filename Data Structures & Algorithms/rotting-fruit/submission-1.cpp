class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push(pair(i, j));
            }
        }

        vector<vector<int>> visited(m, vector<int>(n, -1));
        int distance = 0;
        while (!q.empty()) {
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int pi = p.first, pj = p.second;

                if (visited[pi][pj] != -1 || grid[pi][pj] == 0) continue;
                visited[pi][pj] = distance;

                if (pi-1 >= 0) q.push(pair(pi-1, pj));
                if (pi+1 < m) q.push(pair(pi+1, pj));
                if (pj-1 >= 0) q.push(pair(pi, pj-1));
                if (pj+1 < n) q.push(pair(pi, pj+1));
            }
            distance++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == -1) return -1;
            }
        }
        return max(0, distance-2);
    }
};
