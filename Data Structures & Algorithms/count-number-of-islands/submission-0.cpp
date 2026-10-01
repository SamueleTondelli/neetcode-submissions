class Solution {
public:
    void clear_island(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        clear_island(grid, i+1, j);
        clear_island(grid, i-1, j);
        clear_island(grid, i, j+1);
        clear_island(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n_islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    n_islands++;
                    clear_island(grid, i, j);
                }
            }
        }
        return n_islands;
    }
};
