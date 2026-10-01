class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push(pair(i, j));
            }
        }

        vector<vector<bool>> visited(m, vector(n, false));
        int distance = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int k = 0; k < q_size; k++) {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first, j = p.second;

                if (visited[i][j] || grid[i][j] == -1) continue;
                visited[i][j] = true;

                grid[i][j] = distance;
                if (i-1 >= 0) q.push(pair(i-1, j));
                if (i+1 < m) q.push(pair(i+1, j));
                if (j-1 >= 0) q.push(pair(i, j-1));
                if (j+1 < n) q.push(pair(i, j+1));
            }

            distance++;
        }
    }
};
