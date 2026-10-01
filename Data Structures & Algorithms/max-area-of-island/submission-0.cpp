class Solution {
public:
    int get_area_clear(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + get_area_clear(grid, i+1, j) + get_area_clear(grid, i-1, j) + get_area_clear(grid, i, j+1) + get_area_clear(grid, i, j-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, get_area_clear(grid, i, j));
                }
            }
        }
        return max_area;
    }
};
